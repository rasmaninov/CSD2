import simpleaudio as sa
import time as ti
import numpy as np
from midiutil import MIDIFile


hihat = sa.WaveObject.from_wave_file("hihat.wav")
snare = sa.WaveObject.from_wave_file("snare.wav")
kick = sa.WaveObject.from_wave_file("kick.wav")

events = []
events_saving = []
hihat_timestamp = []
kick_timestamp  = []
snare_timestamp = []

BPM = 120
timesig_1 = 4   #first half of time signature
timesig_2 = 4   #second half of time signature
bar_dur = 4.0  # 1 = 1/4 note for a 4/4
note_dur = 0.125 # 1/16 note in s
base_length = 64 #length of sequence in amount of 16th notes (sequence is 4 bars long)
base_sequence = 0
base_durations = [] #timestamps of every 16th note
current_time = 0  #used for determing base_durations
#variables with "valid" in front are for validating input
valid_BPM = False
valid_timesig_1 = False
valid_timesig_2 = False
valid_answer = False

#start running

#creating bounds for bpm
while not valid_BPM:
    try:
        BPM = int(input("What BPM do you want? 20-400 : "))
    except ValueError:
        print("This is not a number")
        continue
    if BPM <= 400 and BPM >= 20:
        valid_BPM = True
    else:
        print('Error boy, out of BPM Bounds')
#creating note duration from bpm in seconds per 16th note
note_dur = ((60/BPM)/4)
#creating bounds for timesignature
while not valid_timesig_1 and not valid_timesig_2:
    try:
        timesig_1, timesig_2 = input("What time signature do you want? x/y :").split("/")
        timesig_1 = int(timesig_1)
        timesig_2 = int(timesig_2)
    except ValueError:
        print('This is not a correct input')
        continue
    #checking if second half of signature is a power of 2 and if first half is between 1 and 16
    if timesig_1 <= 16 and timesig_1>= 1 and (timesig_2 & timesig_2-1) == 0 and timesig_2 > 1:
        valid_timesig_1 = True
        valid_timesig_2 = True
    else:
        print('Error boy, out of Bounds')
#going from timesignature to the total duration of 1 bar in 1/4 note value
calc = timesig_2 / 4
bar_dur = timesig_1 / calc
print(bar_dur)
#going from 1 bar to 4 bars and back to total number of 16th notes
base_length = int(bar_dur*4*4)
#creating timestamps for every 16th note in loop
for x in range(base_length):
    base_durations.append(current_time)
    current_time = current_time + note_dur
#create sequence based on weighted chance
for x in range(base_length):
    if x < base_length:
        chance = np.random.choice([1,2,3,4,5,6,7], p = [0.25, 0.1, 0.1, 0.1, 0.05, 0.1, 0.3])
        if (chance == 1):
            hihat_timestamp.append(base_durations[x])
        if (chance == 2):
            snare_timestamp.append(base_durations[x])
        if (chance == 3):
            kick_timestamp.append(base_durations[x])
        if (chance == 4):
            hihat_timestamp.append(base_durations[x])
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
            'instrument' : 'hihat'
        })
    for kick in kick_timestamp:
        events.append({
            'timestamp' : kick,
            'instrument' : 'kick'
        })
    for snare in snare_timestamp:
        events.append({
            'timestamp' : snare,
            'instrument' : 'snare'
        })
createEventList()
#sort the events
def get_timestamp(events):
    return events.get('timestamp')
events.sort(key = get_timestamp)
#making an extra list to for writing to midifile
events_saving = events.copy()
#define the noteevents
def noteEvent(events):

    if events['instrument'] == 'snare':
        snare.play()

    if events['instrument'] == 'kick':
        kick.play()

    if events['instrument'] == 'hihat':
        hihat.play()
#so it wil play correctly
kick.play()
#calibrating time
t0 = ti.time()
#play loop
while len(events) > 0 :
    t = ti.time() - t0
    if (t >= events[0].get('timestamp')):
        if (events[0].get('instrument') == 'hihat'):
            noteEvent({
                'instrument':'hihat'
            })
            events.pop(0)
        if (events[0].get('instrument') == 'kick'):
            noteEvent({
                'instrument':'kick'
            })
            events.pop(0)
        if (events[0].get('instrument') == 'snare'):
            noteEvent({
                'instrument':'snare'
            })
            events.pop(0)
        ti.sleep(0.001)

#writing loop to midi
# create your midi object # Midi extraction made possible by docentjes
mf = MIDIFile(1)
track = 0
time = 0
mf.addTrackName(0,0, "Drums")
mf.addTempo(0,0,BPM)
channel = 0
volume = 60
# saving midiloop and validating input
while not valid_answer:
    try:
        save = str(input("do you want to save this loop? y/n: "))
        if (save == "y") :
            while len(events_saving):
                if (len(events_saving) > 0):

                    if (len(events_saving) > 0 and events_saving[0].get('instrument') == 'hihat'):
                        pitch = 42
                        time = events_saving[0].get('timestamp') * 2
                        duration = note_dur
                        mf.addNote(track, channel, pitch, time, duration, volume)
                        events_saving.pop(0)

                    if (len(events_saving) > 0 and events_saving[0].get('instrument') == 'kick'):
                        pitch = 36
                        time = events_saving[0].get('timestamp') * 2
                        duration = note_dur
                        mf.addNote(track, channel, pitch, time, duration, volume)
                        events_saving.pop(0)

                    if (len(events_saving) > 0 and events_saving[0].get('instrument') == 'snare'):
                        pitch = 38
                        time = events_saving[0].get('timestamp') * 2
                        duration = note_dur
                        mf.addNote(track, channel, pitch, time, duration, volume)
                        events_saving.pop(0)
                else:

                    break
            with open("mysong.mid",'wb') as outf:
                mf.writeFile(outf)
            print("done, loop saved")
            break
        elif (save == "n"):
            print('done, loop is deleted')
            break
        elif not (save == "y") or (save == "n"):
            print("wrong input")
            continue

    except ValueError:
        print("wrong input")
