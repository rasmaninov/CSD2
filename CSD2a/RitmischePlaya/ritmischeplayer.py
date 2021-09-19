import simpleaudio as sa
import time

noteLengthR = [ ]
# notelength relatieve waarde
noteLengthA = 0
# notelength absolute waarde

print("Hoeveel samples wil je spelen?")
numPlaybackTimes = input("")
numPlaybackTimes = int(numPlaybackTimes)

for x in range(numPlaybackTimes) :
    noot = input("hoelang moet de nootduur zijn? (in notenwaarden, 1 = kwartnoot) ")
    noot = float(noot)
    noteLengthR.append(noot)

print(noteLengthR)

BPM = input("wat is uw gewenste BPM? ")
BPM = int(BPM)
BPM = 60000/BPM

print(BPM)
# for x in range(numPlaybackTimes) :

for x in range(numPlaybackTimes) :
    noteLengthA = noteLengthR[x] * BPM
    print(noteLengthA)

    wave_obj = sa.WaveObject.from_wave_file("kick.wav")
    play_obj = wave_obj.play()
    time.sleep(noteLengthA/1000)

print("uitgespeeld")
