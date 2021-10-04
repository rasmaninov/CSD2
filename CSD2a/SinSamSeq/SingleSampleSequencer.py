import simpleaudio as sa
import time

noteDurations = []
timestamps16th= []
timestamp = []
sTh = 125
steps = 8
BPM = 120

print("BPM is nu",BPM)
BPM = input("of? ")
print("OK BPM is", BPM)

print("er zijn nu", steps, "stappen")
steps = input("hoeveel stappen in je sequence bro??")
steps = int(steps)
print("OK er zijn nu", steps, "stappen")


for x in range(steps) :
    print("geef je notenwaarde voor stap", x+1)
    stap = input("")
    stap = float(stap)
    noteDurations.append(stap)


currentTime = 0
# ^ thanks to jochem
for x in range(steps):

    timestamps16th.append(currentTime)
    noteDurations[x] = noteDurations[x] * 4
    currentTime = currentTime + noteDurations[x]

sTh = float(sTh)
BPM = float(BPM)
sTh = (60000/BPM)/4

for x in range(steps):

    timestamp.append(( sTh * timestamps16th[x])/1000)

print(timestamp)


Tabla = sa.WaveObject.from_wave_file("Tabla.wav")


t0 = time.time()
print(len(timestamp))

while len(timestamp) > 0:
    t = time.time() - t0

    if(t >= timestamp[0]):
        Tabla.play()
        timestamp.pop(0)
        

    time.sleep(0.0001)

time.sleep(1)
print("klaar")
