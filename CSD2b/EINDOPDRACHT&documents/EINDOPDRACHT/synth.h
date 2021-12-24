#pragma once
#include <iostream>
#include "oscillator.h"
#include <math.h>
#include "sine.h"
#include "saw.h"
#include "square.h"


class Synth
{
public:
  Synth(float midiPitch, double samplerate);
  ~Synth();

  // go to next sample
  void tick();
  // return the current sample
  double getSample();
  // change the Oscillator pitch
  void pitchChange(float newPitch);
  // setting the oscillator pitch
  void setMidiPitch(float pitch);

protected:
  float midiPitch;
  // calculating the next sample combining different oscillators
  virtual void calculate() = 0;
  // update the frequency
  virtual void updateFreq(double freq) = 0;

  // converts midipitch into frequency
  double mtof(float pitch);
  // to cache current sample
  double sample;

};
