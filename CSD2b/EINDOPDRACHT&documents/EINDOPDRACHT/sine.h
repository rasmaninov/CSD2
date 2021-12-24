#pragma once
#include <iostream>
#include "oscillator.h"

class Sine : public Oscillator
{
public:
  Sine();
  Sine(double frequency, double samplerate);
  ~Sine();

private:
  // calculating next sample
  void calcNextSample() override;

};
