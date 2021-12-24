#pragma once
#include <iostream>

class Oscillator
{
public:
  Oscillator(double _frequency, double _samplerate);
  ~Oscillator();

  // initialize the oscillator
  void initialize(double samplerate);
  // go to next sample
  void tick();

  // setters and getters
  // set the frequency
  void setFrequency(double frequency);
  // get the sample
  double getSample();
  // get the frequency
  double getFrequency();

protected:
  // passing on the calcNextSample to the sub oscillators
  virtual void calcNextSample() = 0;

  double phase;
  double sample;
  double samplerate;
  double frequency;
  double amplitude;

};
