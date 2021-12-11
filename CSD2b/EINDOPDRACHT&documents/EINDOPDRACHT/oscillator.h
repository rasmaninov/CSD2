#pragma once
#include <iostream>

class Oscillator
{
public:
  Oscillator();
  Oscillator(double frequency, double samplerate , double phase , double sample , double amplitude);
  ~Oscillator();
  // Initialize(double phase, double sample, double amplitude);

protected:
  double phase;
  double sample;
  double samplerate;
  double frequency;
  double amplitude;

};
