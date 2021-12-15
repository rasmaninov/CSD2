#include "simplesynth.h"
#include "sine.h"

Simple::Simple() : Simple(0,0) {}

Simple::Simple(float midiPitch, double samplerate) : Synth(midiPitch, samplerate) {
std::cout << "Con Simple" << std::endl;
// this -> midiPitch = midiPitch;
}

Simple::~Simple() {
std::cout << "Decon Simple" << std::endl;
}

void Simple::calculate() {
  // sine.tick();
  // sample = sine.getSample();
}
