#include "simplesynth.h"


Simple::Simple() : Simple(0,0) {}

Simple::Simple(float midiPitch, double samplerate) : Synth(midiPitch, samplerate) {
  std::cout << "Con Simple" << std::endl;
  sine.initialize(samplerate);
  setMidiPitch(midiPitch);  
}

Simple::~Simple() {
std::cout << "Decon Simple" << std::endl;
}

void Simple::calculate() {
  // std::cout<<"calc"<<std::endl;
  sine.tick();
  sample = sine.getSample();
}

void Simple::updateFreq(double freq) {
  sine.setFrequency(freq);
}
