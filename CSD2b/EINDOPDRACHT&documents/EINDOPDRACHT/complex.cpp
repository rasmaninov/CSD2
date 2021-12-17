#include "complex.h"

Complex::Complex() : Complex(0,0) {}

Complex::Complex(float midiPitch, double samplerate) : Synth(midiPitch, samplerate) {
  std::cout << "con Complex" << std::endl;
  saw.initialize(samplerate);
  square.initialize(samplerate);
  setMidiPitch(midiPitch);
}

Complex::~Complex() {
std::cout << "decon Complex" << std::endl;
}


void Complex::calculate(){
saw.tick();
square.tick();
sample2 = square.getSample();
sample1 = saw.getSample();
sample = sample1 * sample2;

}

void Complex::updateFreq(double freq) {
  saw.setFrequency(freq);
  square.setFrequency(freq);
}
