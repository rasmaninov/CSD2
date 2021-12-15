#include "synth.h"

Synth::Synth(float midiPitch, double samplerate) : sample(0)
{
  std::cout << "Con Synth" << std::endl;
  sine.initialize(samplerate);
  setMidiPitch(midiPitch);

}

Synth::~Synth() {
  std::cout << "Decon Synth" << std::endl;
}

void Synth::tick(){
  sine.tick();
  sample = sine.getSample();
  calculate();
}


double Synth::getSample(){
  return sample;
}

void Synth::setMidiPitch(float pitch){

  midiPitch = pitch;

  double freq = mtof(midiPitch);
  sine.setFrequency(freq);
}

double Synth::mtof(float pitch){
  return pow(2.0, (pitch - 69.0)/12.0) * 440;
}

void calculate () {}
