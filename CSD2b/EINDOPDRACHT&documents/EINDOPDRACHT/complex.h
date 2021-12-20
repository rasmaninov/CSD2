#pragma once
#include "synth.h"
#include "saw.h"
#include "square.h"
#include "sine.h"

class Complex : public Synth {
public:
  Complex();
  Complex(float midiPitch, double samplerate);
  ~Complex();
  double sample1 = 0;
  double sample2 = 0;
  double sample3 = 0;
  double sample4 = 0;
  double sample5 = 0;
  double sample6 = 0;
  double sample7 = 0;


private:
  void calculate() override;
  void updateFreq(double freq) override;
  Sine one;
  Sine two;
  Sine three;
  Sine four;
  Sine five;
  Sine six;
  Sine seven;
};
