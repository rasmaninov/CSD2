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

  Sine oscs[8];
  double samples[8];
  double ratios[8] = {1, 1.30, 2.63, 5.32, 7.28, 9.29, 11.20, 15.84};
  
private:
  void calculate() override;
  void updateFreq(double freq) override;

};
