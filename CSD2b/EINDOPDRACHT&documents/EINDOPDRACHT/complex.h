#pragma once
#include "synth.h"

class Simple : public Synth {
public:
  Simple();
  Simple(float midiPitch, double samplerate);
  ~Simple();
  calculate();


// private:

};
