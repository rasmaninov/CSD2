#pragma once
#include <iostream>
#include "oscillator.h"
#include "fxbase.h"


class Tremolo : public Effect
{
public:
  Tremolo(float samplerate, float modFreq = 10.0f, float modDepth = 1.0f);
  ~Tremolo();

  void setModFreq(float modFreq);
  void applyEffect(float& input, float& output) override;

protected:

  Oscillator* m_osc;

  float m_modDepth;
  float m_modSignal = 0;
};
