import simpleaudio as sa

zovaak = input("hoevaak spelen broer? zovaak: ",)


zovaak = int(zovaak)

for x in range(zovaak):
    print ((x+1),"keer")
    wave_obj = sa.WaveObject.from_wave_file("kick.wav")
    play_obj = wave_obj.play()
    play_obj.wait_done()


print(zovaak, "keer afgespeeld")
