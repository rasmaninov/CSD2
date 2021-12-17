#pragma once
#include <iostream>
#include "oscillator.h"
#include <math.h>
#include "sine.h"
#include "saw.h"


class Synth
{
public:
  Synth(float midiPitch, double samplerate);
  ~Synth();
  // go to next sample
  void tick();

  // return the current sample


  double getSample();
  void setMidiPitch(float pitch);

protected:
  virtual void calculate() = 0;
  virtual void updateFreq(double freq) = 0;
  float midiPitch;
  // returns a frequency
  double mtof(float pitch);

  // to cache current sample
  double sample;

};
