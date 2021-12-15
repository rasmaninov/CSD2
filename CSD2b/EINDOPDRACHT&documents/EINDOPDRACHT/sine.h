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
  void calcNextSample() override;

};
