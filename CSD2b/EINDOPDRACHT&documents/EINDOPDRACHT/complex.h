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
  double sample2 = 1;


private:
  void calculate() override;
  void updateFreq(double freq) override;
  Saw saw;
  Sine square;
};
