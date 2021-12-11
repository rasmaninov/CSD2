#pragma once
#include <iostream>

class Sine
{
public:
  Sine(double frequency, double samplerate);
  ~Sine();

  // void calculate();
  float getSample();

  void tick();

  void setFrequency(float frequency);
  float getFrequency();
  // Tick();
private:
  double frequency;
  double amplitude;
  double phase;
  double sample;
  double samplerate;
};
