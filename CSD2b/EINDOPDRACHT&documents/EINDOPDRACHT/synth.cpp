#include "synth.h"

Synth::Synth(float midiPitch, double samplerate) : sample(0)
{
  std::cout << "con Synth" << std::endl;
}

Synth::~Synth() {
  std::cout << "decon Synth" << std::endl;
}

void Synth::tick(){
  calculate();
}

void Synth::pitchChange(float newPitch){
  setMidiPitch(newPitch);
}

double Synth::getSample(){
  return sample;
}

void Synth::setMidiPitch(float pitch){
  midiPitch = pitch;

  double freq = mtof(midiPitch);
  updateFreq(freq);
}

double Synth::mtof(float pitch){
  return pow(2.0, (pitch - 69.0)/12.0) * 440;
}

void calculate () {}
