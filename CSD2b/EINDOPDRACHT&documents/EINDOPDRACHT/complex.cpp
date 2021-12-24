#include "complex.h"
#include <map>
#include <string>

Complex::Complex() : Complex(0,0) {}


Complex::Complex(float midiPitch, double samplerate) : Synth(midiPitch, samplerate) {
  std::cout << "con Complex" << std::endl;

  one.initialize(samplerate);
  two.initialize(samplerate);
  three.initialize(samplerate);
  four.initialize(samplerate);
  five.initialize(samplerate);
  six.initialize(samplerate);
  seven.initialize(samplerate);
  eight.initialize(samplerate);
  setMidiPitch(midiPitch);
}

Complex::~Complex() {
std::cout << "decon Complex" << std::endl;
}


void Complex::calculate(){
one.tick();
two.tick();
three.tick();
four.tick();
five.tick();
six.tick();
seven.tick();
sample1 = one.getSample();
sample2 = two.getSample();
sample3 = three.getSample();
sample4 = four.getSample();
sample5 = five.getSample();
sample6 = six.getSample();
sample7 = seven.getSample();
sample8 = eight.getSample();
sample = 0.8 * sample1 + 0.4 * sample2 + 0.4 * sample3 + 0.3 * sample4 +
0.25 * sample5 + 0.2 *sample6 + 0.2 * sample7 + 0.5 * sample8;

}

void Complex::updateFreq(double freq) {
  one.setFrequency(freq);
  two.setFrequency(1.30*freq);
  three.setFrequency(2.63*freq);
  four.setFrequency(5.32*freq);
  five.setFrequency(7.28*freq);
  six.setFrequency(9.29*freq);
  seven.setFrequency(11.20*freq);
  eight.setFrequency(15.84*freq);
}
