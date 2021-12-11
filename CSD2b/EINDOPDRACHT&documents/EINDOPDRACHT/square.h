#pragma once
#include <iostream>

class Square
{
public:
  Square(double frequency, double samplerate);
  ~Square();

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
