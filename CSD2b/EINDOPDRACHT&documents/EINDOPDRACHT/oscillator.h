#pragma once
#include <iostream>

class Oscillator
{
public:
  Oscillator();
  ~Oscillator();


protected:
  double phase;
  double sample;
  double samplerate;
  double frequency;
  double amplitude;

};
