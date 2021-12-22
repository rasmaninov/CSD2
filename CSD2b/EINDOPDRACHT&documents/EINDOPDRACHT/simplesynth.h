#pragma once
#include "synth.h"
#include "sine.h"

class Simple : public Synth {
public:
  Simple();
  Simple(float midiPitch, double samplerate);
  ~Simple();

  double sample1 = 0;
  double sample2 = 0;
  int detune = 0;

private:
  void calculate() override;
  void updateFreq(double freq) override;
  Saw one;
  Saw two;
};
