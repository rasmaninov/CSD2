#pragma once

#include <iostream>
#include "oscillator.h"

class Tremolo
{
public:
  Tremolo(float freq, int samplerate);
  ~Tremolo();

  void setModFreq(float freq);
  float processFrame(float sample);

private:

  Oscillator* osc;
  float modSignal;
};
