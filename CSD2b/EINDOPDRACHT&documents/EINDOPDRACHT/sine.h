#ifndef _SINE_H_
#define _SINE_H_
#include <iostream>

class Sine
{
public:
  //Constructor and destructor
  Sine(float frequency, double samplerate);
  ~Sine();

  //return the current sample
  float getSample();
  // go to next sample
  void tick();

  //getters and setters
  void setFrequency(float frequency);
  float getFrequency();

private:
  float frequency;
  float amplitude;
  float phase;
  // sample contains the current sample
  float sample;
  double samplerate;
};

#endif
