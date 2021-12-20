#include "complex.h"
//in the complex synth, I synthesize a clarinet using additive synthesis
//I have used this formula,
//s(t) = \sin(w) + 0.75 \sin(3 w) + 0.5 \sin(5 w) + 0.14 \sin(7 w) + 0.5 \sin(9 w) + 0.12 \sin(11 w) + 0.17 \sin(13 w)
//in this case, w = 2(PI)(f0), where f0 is the fundamental frequency.
//the formula was found on this Stanford webpage : https://ccrma.stanford.edu/~serafin/320/assign2/Synthesis_clarinet.html

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
sample = sample1 + 0.75 * sample2 + 0.5 * sample3 + 0.14 * sample4 +
0.5 * sample5 + 0.12 *sample6 + 0.17 * sample7;

}

void Complex::updateFreq(double freq) {
  one.setFrequency(freq);
  two.setFrequency(3*freq);
  three.setFrequency(5*freq);
  four.setFrequency(7*freq);
  five.setFrequency(9*freq);
  six.setFrequency(11*freq);
  seven.setFrequency(13*freq);
}
