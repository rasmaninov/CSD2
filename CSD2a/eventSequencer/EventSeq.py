import simpleaudio as sa
import time

zestiende = 0.125
kick = sa.WaveObject.from_wave_file("kick.wav")
snare = sa.WaveObject.from_wave_file("snare.wav")
hihat = sa.WaveObject.from_wave_file("hihat.wav")

HHts =[0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]
Kts = [0,4,7,8,12]
Sts = [2,6,10,14]

kick = {
'timestamp' : [1],
'instrument' : kick
}

snare = {
'timestamp' : [1],
'instrument' : snare
}

hihat = {
'timestamp' : [0],
'instrument' : hihat
}

def noteEvent(event):

    event['instrument'].play()

noteEvent(hihat)
time.sleep(1)
t0 = time.time()

while len(HHts) > 0:
    t = time.time() - t0
    if HHts:

        if(t >= Sts[0]*0.25):
            noteEvent(snare)
            Sts.pop(0)
            snare['timestamp'] = Sts[0]
        if(t >= Kts[0]*0.25):
            noteEvent(kick)
            Kts.pop(0)
            kick['timestamp'] = Kts[0]
        if(t >= HHts[0]*0.25):
            noteEvent(hihat)
            HHts.pop(0)
            hihat['timestamp'] = HHts[0]
        time.sleep(0.0001)
    else:
        break
time.sleep(1)
print("klaar")
