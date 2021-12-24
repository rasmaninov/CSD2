#pragma once
#include "synth.h"

class Simple : public Synth {
public:
  // initialize
  Simple();

  Simple(float midiPitch, double samplerate);
  ~Simple();

  double sample1 = 0;
  double sample2 = 0;
  double sample3 = 0;
  // the amount of detune
  int detune = 0;

private:
  // calculating next sample
  void calculate() override;
  // updating the frequency
  void updateFreq(double freq) override;
  Saw one;
  Saw two;
  Square three;
};
