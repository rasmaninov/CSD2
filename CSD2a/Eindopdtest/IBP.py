import simpleaudio as sa
import time
import numpy as np
from TestModuleAlgo import split_note

note_dur = 0.5 #noteduration
hihat = sa.WaveObject.from_wave_file("hihat.wav")
snare = sa.WaveObject.from_wave_file("snare.wav")
kick = sa.WaveObject.from_wave_file("kick.wav")
events = []

base_sequence       = [1,1]
base_durations      = []
t1_ts               = []
t2_ts               = []
tl_ts               = []
khanda_rupaka       = [2, 5]
tisra_dhruva        = [3, 2, 3, 3]
random_range        = 0.25
random_diminisher   = 0.75
beat_cycles         = 4
#tala is up for user input/ tala = time signature
tala = khanda_rupaka
aksharam = []
current_beat = 0

for x in range((len(tala) * 3 + 1)):
    aksharam.append(current_beat)
    current_beat = current_beat + tala[x%len(tala)]

base_sequence[0] = aksharam[len(tala)*3]


#creating notedurations for hihat
for i in range(5):
    num_splits = 2 ** i

    for j in range(num_splits):
        index = j * 2
        split_note(base_sequence, index, random_range)

    random_range = int(random_range * random_diminisher + 0.5)

current_time = 0 #thanks Jochem

#turn notedurations into timestamps
for i in range(len(base_sequence)):
    base_durations.append(current_time * note_dur)
    current_time = current_time + base_sequence[i]

#creating timesamples for snare based on hihat

for x in range(len(aksharam)):
    if (x < len(base_durations)):
        chance = np.random.choice([1, 2, 3, 4, 5, 6], p = [0.2, 0.15, 0.2, 0.2, 0.2, 0.05])
        if (chance == 3 ):
            t2_ts.append(base_durations.pop(x))
        if (chance == 2):
            tl_ts.append(base_durations.pop(x))
        if (chance == 1):
            t1_ts.append(base_durations.pop(x))
        if (chance == 4):
            t2_ts.append(base_durations.pop(x))
            t1_ts.append(base_durations.pop(x))
        if (chance == 5):
            t1_ts.append(base_durations.pop(x))
            tl_ts.append(base_durations.pop(x))
        if (chance == 6):
            t2_ts.append(base_durations.pop(x))
            tl_ts.append(base_durations.pop(x))
            t1_ts.append(base_durations.pop(x))
        print("pop")

for i in range(1):
    num_splits = 2 ** i

    for j in range(num_splits):
        index = j * 2
        split_note(t1_ts, index, random_range)

    random_range = int(random_range * random_diminisher + 0.5)


#Algorithms should be done here
#Timestamps for every layer should be created
#Turn timestamps into sequenceable events

def createeventsList():
    for hat in t1_ts:
        events.append({
            'timestamp' : hat,
            'instrument' : 'Tab1',
            # 'note_event' : hihat.play()

        })
    for tab_long in tl_ts:
        events.append({
            'timestamp' : tab_long,
            'instrument' : 'tab_long',
            # 'note_event' : kick.play()
        })
    for Tab2 in t2_ts:
        events.append({
            'timestamp' : Tab2,
            'instrument' : 'Tab2',
            # 'note_event' :snare.play()
        })

createeventsList()

#event timestamp sorting from low to high
def get_timestamp(events):
    return events.get('timestamp')
events.sort(key = get_timestamp)
print(events)

def note_events(events):

    if events['instrument'] == 'Tab2':
        snare.play()

    if events['instrument'] == 'tab_long':
        kick.play()

    if events['instrument'] == 'Tab1':
        hihat.play()

time.sleep(1)
print("go")
t0 = time.time()



#play sequences for : hi, low, mid
while len(events) > 0: # alles in elkaar stoppen
    t = time.time() - t0

    if(t >=  events[0].get('timestamp')):

        if (len(events) > 0 and events[0].get('instrument') == 'Tab1'):
            note_events({
            'instrument':'Tab1'
            })
            events.pop(0)

        if  (len(events) > 0 and events[0].get('instrument') == 'Tab2'):
            note_events({
                'instrument':'Tab2'
            })
            events.pop(0)

        if (len(events) > 0 and events[0].get('instrument') == 'tab_long'):
            note_events({
                'instrument':'tab_long'
            })
            events.pop(0)

        time.sleep(0.01)

time.sleep(0.5)

print("klaar")
