#pragma once
#include <iostream>
#include "oscillator.h"

class Saw : public Oscillator
{
public:
  Saw();
  Saw(double frequency, double samplerate);
  ~Saw();

private:
    void calcNextSample() override;
};
