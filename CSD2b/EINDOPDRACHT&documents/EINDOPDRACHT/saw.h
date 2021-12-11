#pragma once
#include <iostream>

class Saw
{
public:
  Saw(double frequency, double samplerate);
  ~Saw();

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
