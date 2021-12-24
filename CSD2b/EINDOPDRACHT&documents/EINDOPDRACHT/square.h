#pragma once
#include <iostream>
#include "oscillator.h"

class Square : public Oscillator
{
public:
  Square();
  Square(double frequency, double samplerate);
  ~Square();

private:
  // calculating next sample
  void calcNextSample() override;
};
