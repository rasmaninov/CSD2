import simpleaudio as sa
import time
from TestModuleAlgo import split_note
nD = 0.25 #noteduration
Tab_1_Sample = sa.WaveObject.from_wave_file("Tab1.wav")
Tab_2_Sample = sa.WaveObject.from_wave_file("Tab2.wav")
tab_long_sample = sa.WaveObject.from_wave_file("tablong.wav")
events = []

t1_sequence = [28, 4]
t1_ts = []
t2_ts = []
tl_ts = []

random_range = 12
random_diminisher = 0.5

for i in range(3):
    num_splits = 2 ** i

    for j in range(num_splits):
        index = j * 2
        split_note(t1_sequence, index, random_range)

    random_range = int(random_range * random_diminisher + 0.5)

print(t1_sequence, "sequens", len(t1_sequence))

current_time = 0 #thanks jochem

for i in range(len(t1_sequence)):
    t1_ts.append(current_time)
    current_time = current_time + t1_sequence[i]

print(t1_ts, "timestamps", len(t1_ts))


def createeventsList():
    for hat in t1_ts:
        events.append({
            'timestamp' : hat,
            'instrument' : 'Tab1'
        })
    for tab_long in tl_ts:
        events.append({
            'timestamp' : tab_long,
            'instrument' : 'tab_long'
        })
    for Tab2 in t2_ts:
        events.append({
            'timestamp' : Tab2,
            'instrument' : 'Tab2'
        })


createeventsList()

def get_timestamp(events):
    return events.get('timestamp')
events.sort(key =get_timestamp)

def note_events(events):

    if events['instrument'] == 'Tab2':
        Tab_2_Sample.play()

    if events['instrument'] == 'tab_long':
        tl_ts.play()

    if events['instrument'] == 'Tab1':
        Tab_1_Sample.play()

note_events({
    'instrument':'Tab1'
})

time.sleep(1)
print("go")
t0 = time.time()

while len(events):
    t = time.time() - t0
    if (len(events)> 0):
        if (len(events) > 0
        and t >= (events[0].get('timestamp')*nD)
        and events[0].get('instrument') == 'Tab1'):
            note_events({
                'instrument':'Tab1'
            })
            events.pop(0)

        if (len(events) > 0
        and t >= (events[0].get('timestamp')*nD)
        and events[0].get('instrument') == 'tab_long'):
            note_events({
                'instrument':'tab_long'
            })
            events.pop(0)

        if (len(events) > 0
        and t >= (events[0].get('timestamp')*nD)
        and events[0].get('instrument') == 'Tab2'):
            note_events({
                'instrument':'Tab2'
            })
            events.pop(0)

        time.sleep(0.01)
    else:
        break

time.sleep(0.5)

print("klaar")
