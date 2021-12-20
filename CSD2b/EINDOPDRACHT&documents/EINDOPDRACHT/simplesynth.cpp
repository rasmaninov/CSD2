#include "simplesynth.h"

Simple::Simple() : Simple(0,0) {}

Simple::Simple(float midiPitch, double samplerate) : Synth(midiPitch, samplerate) {
  std::cout << "Con Simple" << std::endl;
  one.initialize(samplerate);
  two.initialize(samplerate);
  setMidiPitch(midiPitch);
}

Simple::~Simple() {
std::cout << "Decon Simple" << std::endl;
}

void Simple::calculate() {
  one.tick();
  two.tick();
  sample1 = one.getSample();
  sample2 = two.getSample();
  sample = (sample1 + sample2) / 2;
}

void Simple::updateFreq(double freq) {
  one.setFrequency(freq + 5);
  two.setFrequency(freq - 5);
}
