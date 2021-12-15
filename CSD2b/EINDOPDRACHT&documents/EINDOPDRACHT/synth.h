#pragma once
#include <iostream>
#include "sine.h"
#include <math.h>

class Synth
{
public:
  Synth(float midiPitch, double samplerate);
  ~Synth();
  // go to next sample
  void tick();
  // setters and getters
  // return the current sample


  double getSample();
  void setMidiPitch(float pitch);

protected:
  virtual void calculate() = 0;
  float midiPitch;
  // returns a frequency
  double mtof(float pitch);

  // to cache current sample
  double sample;
  Sine sine;

};
