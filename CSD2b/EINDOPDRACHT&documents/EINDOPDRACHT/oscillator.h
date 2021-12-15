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
  // return the current sample
  double getSample();

  //getters and setters
  void setFrequency(double frequency);
  double getFrequency();

protected:
  virtual void calcNextSample() = 0;
  double phase;
  double sample;
  double samplerate;
  double frequency;
  double amplitude;

};
