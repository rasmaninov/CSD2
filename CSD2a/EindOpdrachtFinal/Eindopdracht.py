import simpleaudio as sa
import time
import numpy as np

hihat = sa.WaveObject.from_wave_file("hihat.wav")
snare = sa.WaveObject.from_wave_file("snare.wav")
kick = sa.WaveObject.from_wave_file("kick.wav")

events = []
base_sequence = 0
base_durations = []

hihat_timestamp = []
kick_timestamp  = []
snare_timestamp = []

bar_dur = 3.5  # 1 = 1/4 note
note_dur = 0.125 # 1/16 note in ms
base_length = int(bar_dur*4*4)

current_time = 0


for x in range(base_length):

    base_durations.append(current_time)
    current_time = current_time + note_dur

print(base_durations)

for x in range(base_length):
    if x < base_length:
        chance = np.random.choice([1,2,3,4,5,6], p = [0.3, 0.15, 0.15, 0.15, 0.1, 0.15])
        print(chance)
        time.sleep(0.1)
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

print('tijd is ', t)
time.sleep(2)
print("klaar")
