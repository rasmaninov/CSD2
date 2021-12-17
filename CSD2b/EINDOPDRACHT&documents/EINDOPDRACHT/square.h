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
  void calcNextSample() override;
};
