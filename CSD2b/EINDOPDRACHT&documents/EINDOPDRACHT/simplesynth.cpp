#include "simplesynth.h"


Simple::Simple() : Simple(0,0) {}

Simple::Simple(float midiPitch, double samplerate) : Synth(midiPitch, samplerate) {
std::cout << "Con Simple" << std::endl;
}

Simple::~Simple() {
std::cout << "Decon Simple" << std::endl;
}

void Simple::calculate() {
  // sine.tick();
  // sample = sine.getSample();
}
