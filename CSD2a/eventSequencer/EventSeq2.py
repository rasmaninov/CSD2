import simpleaudio as sa
import time

nD = 0.25 #noteduration
kickSample = sa.WaveObject.from_wave_file("kick.wav")
snareSample = sa.WaveObject.from_wave_file("snare.wav")
hihatSample = sa.WaveObject.from_wave_file("hihat.wav")
HHts =[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 ,11, 12,13, 14]
Kts = [0, 4, 7, 8, 12, 15]
Sts = [2, 6, 10, 14, 15]
event = []


def createEventList():
    for hat in HHts:
        event.append({
            'timestamp' : hat,
            'instrument' : 'hihat'
        })
    for kick in Kts:
        event.append({
            'timestamp' : kick,
            'instrument' : 'kick'
        })
    for snare in Sts:
        event.append({
            'timestamp' : snare,
            'instrument' : 'snare'
        })


createEventList()

def get_timestamp(event):
    return event.get('timestamp')
event.sort(key =get_timestamp)

def noteEvent(event):

    if event['instrument'] == 'snare':
        snareSample.play()

    if event['instrument'] == 'kick':
        kickSample.play()

    if event['instrument'] == 'hihat':
        hihatSample.play()

noteEvent({
    'instrument':'hihat'
})

time.sleep(1)
print("go")
t0 = time.time()

while len(event):
    t = time.time() - t0
    if (len(event)> 0):
        if (len(event) > 0 and t >= (event[0].get('timestamp')*nD) and event[0].get('instrument') == 'hihat'):
            noteEvent({
                'instrument':'hihat'
            })
            event.pop(0)
        if (len(event) > 0 and t >= (event[0].get('timestamp')*nD) and event[0].get('instrument') == 'kick'):
            noteEvent({
                'instrument':'kick'
            })
            event.pop(0)
        if (len(event) > 0 and t >= (event[0].get('timestamp')*nD) and event[0].get('instrument') == 'snare'):
            noteEvent({
                'instrument':'snare'
            })
            event.pop(0)
        time.sleep(0.01)
    else:
        break
time.sleep(0.5)
print("klaar")
