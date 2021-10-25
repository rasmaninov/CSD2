import simpleaudio as sa
import time as ti
import numpy as np
import datetime
from midiutil import MIDIFile
#loading samples Thanks to Ciska
samples = {
    "hihat" : sa.WaveObject.from_wave_file("hihat.wav"),
    "snare" : sa.WaveObject.from_wave_file("snare.wav"),
    "kick" : sa.WaveObject.from_wave_file("kick.wav")
}
running = True
#start running
while running:
    events = [] #regular events list
    events_saving = [] #events list for writing in midi
    hihat_timestamp = []
    kick_timestamp  = []
    snare_timestamp = []

    BPM = 120 #Beats per minute
    timesig_1 = 4   #first half of time signature
    timesig_2 = 4   #second half of time signature
    bar_dur = 4.0  # 1 = 1/4 note for a 4/4
    note_dur = 0.125 # 1/16 note in s
    base_length = 64 #length of sequence in amount of 16th notes (sequence is 4 bars long)
    base_sequence = 0 #note values for every of the x amount in base_length
    base_durations = [] #timestamps of every 16th note
    current_time = 0  #used for determing base_durations
    #variables with "valid" in front are for validating input
    valid_BPM = False
    valid_timesig_1 = False
    valid_timesig_2 = False
    valid_answer = False


    #creating bounds for bpm
    while not valid_BPM:
        try:
            BPM = int(input("What BPM do you want? 20-400 : "))
        except ValueError:
            print("This is not a number")
            continue
        if BPM <= 400 and BPM >= 20:
            note_dur = ((60/BPM)/4)
            print(note_dur)
            valid_BPM = True
        else:
            print('out of Bounds. 20-400 BPM')
    #creating note duration from bpm in seconds per 16th note

    #creating bounds for timesignature
    while not valid_timesig_1 and not valid_timesig_2:
        try:
            timesig_1, timesig_2 = input("What time signature do you want? x/y :").split("/")
            timesig_1 = int(timesig_1)
            timesig_2 = int(timesig_2)
        except ValueError:
            print('wrong input')
            continue
        #checking if second half of signature is a power of 2 and if first half is between 1 and 16
        if timesig_1 <= 16 and timesig_1>= 1 and (timesig_2 & timesig_2-1) == 0 and timesig_2 > 1:
            print(timesig_1, "/", timesig_2)
            valid_timesig_1 = True
            valid_timesig_2 = True
        else:
            print('out of Bounds')
    #going from timesignature to the total duration of 1 bar in 1/4 note value
    calc = timesig_2 / 4
    bar_dur = timesig_1 / calc
    #going from 1 bar to 4 bars and back to total number of 16th notes
    base_length = int(bar_dur*4*4)
    #creating timestamps for every 16th note in loop
    for x in range(base_length):
        base_durations.append(current_time)
        current_time = current_time + note_dur
    #create sequence based on weighted chance
    for x in range(base_length):
        if (x < base_length and x == 0 or x % 2 == 0):
            chance = np.random.choice([1,2,3,4,5,6,7], p = [0.25, 0.05, 0.1, 0.05, 0.1, 0.25, 0.2])
            if (chance == 1):
                hihat_timestamp.append(base_durations[x])
            if (chance == 2):
                snare_timestamp.append(base_durations[x])
            if (chance == 3):
                kick_timestamp.append(base_durations[x])
            if (chance == 4):
                kick_timestamp.append(base_durations[x])
                snare_timestamp.append(base_durations[x])
            if (chance == 5):
                hihat_timestamp.append(base_durations[x])
                snare_timestamp.append(base_durations[x])
            if (chance == 6):
                hihat_timestamp.append(base_durations[x])
                kick_timestamp.append(base_durations[x])
        elif (x < base_length and x == 4 or x % 8 == 0):
            chance = np.random.choice([1,2,3], p = [0.5,0.2,0.3])
            if (chance == 1):
                snare_timestamp.append(base_durations[x])
            if (chance == 2):
                kick_timestamp.append(base_durations[x])
        elif (x < base_length and x == 1 or x % 1 == 0 ):
            chance = np.random.choice([1,2,3,4,5,6,7], p = [0.15, 0.0, 0.05, 0.05, 0.1, 0.1, 0.55])
            if (chance == 1):
                hihat_timestamp.append(base_durations[x])
            if (chance == 2):
                snare_timestamp.append(base_durations[x])
            if (chance == 3):
                kick_timestamp.append(base_durations[x])
            if (chance == 4):
                snare_timestamp.append(base_durations[x])
                kick_timestamp.append(base_durations[x])
            if (chance == 5):
                hihat_timestamp.append(base_durations[x])
                snare_timestamp.append(base_durations[x])
            if (chance == 6):
                hihat_timestamp.append(base_durations[x])
                kick_timestamp.append(base_durations[x])
        else:
            break
    # create sequencable events list
    def createEventList():
        for hat in hihat_timestamp:
            events.append({
                'timestamp' : hat,
                'instrument' : 'hihat',
                'pitch' : '42'
            })
        for kick in kick_timestamp:
            events.append({
                'timestamp' : kick,
                'instrument' : 'kick',
                'pitch' : '36'
            })
        for snare in snare_timestamp:
            events.append({
                'timestamp' : snare,
                'instrument' : 'snare',
                'pitch' : '38'
            })
    createEventList()
    #sort the events
    def get_timestamp(events):
        return events.get('timestamp')
    events.sort(key = get_timestamp)
    #making an extra list to for writing to midifile
    events_saving = events.copy()
    #calibrating time
    t0 = ti.time()
    #play loop
    while events:
        t = ti.time() - t0
        if (t >= events[0].get('timestamp')):
            samples[events[0]['instrument']].play()
            events.pop(0)
            ti.sleep(0.001)

    #writing loop to midi
    #create your midi object # Midi extraction made possible by docentjes
    mf = MIDIFile(1)
    track = 0
    time = 0
    mf.addTrackName(0,0, "Drums")
    mf.addTempo(0,0,BPM)
    channel = 0
    volume = 60
    duration = note_dur
    # saving midiloop and validating input thanks to example 6 writemidi
    while not valid_answer:
        try:
            save = str(input("do you want to save this loop? y/n: "))

            if (save == "y") :
                name = input("what to call the file bro :")
                name = name + ".mid"
                while events_saving:
                    time = events_saving[0].get('timestamp') * 2
                    pitch = int(events_saving[0].get('pitch'))
                    mf.addNote(track, channel, pitch, time, duration, volume)
                    events_saving.pop(0)
                with open(name,'wb') as outf:
                    mf.writeFile(outf)
                print("done, loop saved")
                valid_answer = True
            elif (save == "n"):
                print('done, deleted loop')
                valid_answer = True
            elif not (save == "y") or (save == "n"):
                print("wrong input")
                continue

        except ValueError:
            print("wrong input")
    #looping entire loopbuildingsequence
    try:
        runner = str(input("keep going? y/n :"))
        if (runner == "y" ) :
            running = True
        elif (runner == "n") :
            running = False
            ti.sleep(1)
        elif not (runner == "y" ) or (runner == "n"):
            print("wrong input")
            continue
    except :
        print("wrong input")
print('bye ;_;')
ti.sleep(2)
