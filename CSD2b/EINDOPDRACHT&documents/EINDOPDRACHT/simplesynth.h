#pragma once
#include "synth.h"
#include "sine.h"

class Simple : public Synth {
public:
  Simple();
  Simple(float midiPitch, double samplerate);
  ~Simple();



private:
  void calculate() override;
  void updateFreq(double freq) override;
  Sine sine;
};
