import simpleaudio as sa
import time
import numpy as np

hihat = sa.WaveObject.from_wave_file("hihat.wav")
snare = sa.WaveObject.from_wave_file("snare.wav")
kick = sa.WaveObject.from_wave_file("kick.wav")

events = []
hihat_timestamp = []
kick_timestamp  = []
snare_timestamp = []

bar_dur = 3.5  # 1 = 1/4 note
note_dur = 0.125 # 1/16 note in ms
base_length = int(bar_dur*4*4) #length of sequence in amount of 16th notes (sequence is 4 bars long)
base_sequence = 0
base_durations = [] #timestamps of every 16th note
current_time = 0  #used for determing base_durations

valid_BPM = False
BPM = 120
valid_timesig_1 = False
valid_timesig_2 = False
timesig_1 = 4   #first half of time signature
timesig_2 = 4   #second half of time signature

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

note_dur = (60/BPM) * 0.25

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

#going from timesignature to bar_dur
calc = timesig_2 / 4
bar_dur = timesig_1 / calc

for x in range(base_length):

    base_durations.append(current_time)
    current_time = current_time + note_dur

print(base_durations)

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

# create events and play sequence
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

def get_timestamp(events):
    return events.get('timestamp')
events.sort(key =get_timestamp)

def noteEvent(events):

    if events['instrument'] == 'snare':
        snare.play()

    if events['instrument'] == 'kick':
        kick.play()

    if events['instrument'] == 'hihat':
        hihat.play()
kick.play()

t0 = time.time()

while len(events):
    t = time.time() - t0

    if (len(events) > 0):

        if (len(events) > 0 and t >= events[0].get('timestamp') and events[0].get('instrument') == 'hihat'):
            noteEvent({
                'instrument':'hihat'
            })
            events.pop(0)
        if (len(events) > 0 and t >= events[0].get('timestamp') and events[0].get('instrument') == 'kick'):
            noteEvent({
                'instrument':'kick'
            })
            events.pop(0)
        if (len(events) > 0 and t >= events[0].get('timestamp') and events[0].get('instrument') == 'snare'):
            noteEvent({
                'instrument':'snare'
            })
            events.pop(0)
        time.sleep(0.01)
    else:

        break

time.sleep(2)
print("klaar")
