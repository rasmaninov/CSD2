#include "synth.h"

Synth::Synth(float midiPitch, double samplerate) : sample(0){
}

Synth::~Synth() {
}

  // go to next sample
void Synth::tick(){
  calculate();
}

  // change the Oscillator pitch
void Synth::pitchChange(float newPitch){
  setMidiPitch(newPitch);
}

  // return the current sample
double Synth::getSample(){
  return sample;
}

  // setting the oscillator pitch
void Synth::setMidiPitch(float pitch){
  midiPitch = pitch;
  double freq = mtof(midiPitch);
    // update the frequency
  updateFreq(freq);
}
  // converts midipitch into frequency
  
double Synth::mtof(float pitch){
  return pow(2.0, (pitch - 69.0)/12.0) * 440;
}
