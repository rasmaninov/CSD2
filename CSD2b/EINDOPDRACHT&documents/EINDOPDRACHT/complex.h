#pragma once
#include "synth.h"
#include "saw.h"


class Complex : public Synth {
public:
  Complex();
  Complex(float midiPitch, double samplerate);
  ~Complex();



private:
  void calculate() override;
  Saw Saw();
};
