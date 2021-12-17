#pragma once
#include "synth.h"
#include "saw.h"
#include "square.h"

class Complex : public Synth {
public:
  Complex();
  Complex(float midiPitch, double samplerate);
  ~Complex();



private:
  void calculate() override;
  void updateFreq(double freq) override;
  Saw saw;
  // Square square;
};
