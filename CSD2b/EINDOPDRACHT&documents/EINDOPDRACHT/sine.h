#pragma once
#include <iostream>
#include "oscillator.h"
class Sine : public Oscillator
{
public:
  Sine(double frequency, double samplerate);
  ~Sine();

  // void calculate();
  float getSample();

  void tick();

  void setFrequency(float frequency);
  float getFrequency();
};
