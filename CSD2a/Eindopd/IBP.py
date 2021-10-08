import simpleaudio as sa
import time

nD = 0.25 #noteduration
Tab1Sample = sa.WaveObject.from_wave_file("Tab1.wav")
Tab2Sample = sa.WaveObject.from_wave_file("Tab2.wav")
TablongSample = sa.WaveObject.from_wave_file("Tablong.wav")
event = []

t1ts = []
t2ts = []
tlts = []

def createEventList():
    for hat in t1ts:
        event.append({
            'timestamp' : hat,
            'instrument' : 'Tab1'
        })
    for Tablong in tlts:
        event.append({
            'timestamp' : Tablong,
            'instrument' : 'Tablong'
        })
    for Tab2 in t2ts:
        event.append({
            'timestamp' : Tab2,
            'instrument' : 'Tab2'
        })


createEventList()

def get_timestamp(event):
    return event.get('timestamp')
event.sort(key =get_timestamp)

def noteEvent(event):

    if event['instrument'] == 'Tab2':
        Tab2Sample.play()

    if event['instrument'] == 'Tablong':
        TablongSample.play()

    if event['instrument'] == 'Tab1':
        Tab1Sample.play()

noteEvent({
    'instrument':'Tab1'
})

time.sleep(1)
print("go")
t0 = time.time()

while len(event):
    t = time.time() - t0
    if (len(event)> 0):
        if (len(event) > 0 and t >= (event[0].get('timestamp')*nD) and event[0].get('instrument') == 'Tab1'):
            noteEvent({
                'instrument':'Tab1'
            })
            event.pop(0)
        if (len(event) > 0 and t >= (event[0].get('timestamp')*nD) and event[0].get('instrument') == 'Tablong'):
            noteEvent({
                'instrument':'Tablong'
            })
            event.pop(0)
        if (len(event) > 0 and t >= (event[0].get('timestamp')*nD) and event[0].get('instrument') == 'Tab2'):
            noteEvent({
                'instrument':'Tab2'
            })
            event.pop(0)
        time.sleep(0.01)
    else:
        break
time.sleep(0.5)
print("klaar")
