#pragma once
#include <iostream>

class Oscillator
{
public:
  Oscillator(double _frequency, double _samplerate);
  ~Oscillator();

  void initialize(double samplerate);

  // go to next sample
  void tick();

  // setters and getters
  void setFrequency(double frequency);
  // return the current sample
  double getSample();

  //getters and setters

  double getFrequency();

protected:

  virtual void calcNextSample() = 0;
  double phase;
  double sample;
  double samplerate;
  double frequency;
  double amplitude;

};
