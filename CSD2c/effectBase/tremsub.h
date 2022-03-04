#pragma once
#include "oscillator.h"
#include "fxbase.h"


class Tremolo : public Effect
{
public:
  Tremolo(float samplerate, float modFreq, float modDepth);
  ~Tremolo();

  void setModFreq(float modFreq);
  // void setModDepth(float modDepth);
  void applyEffect(float& input, float& output) override;

protected:

  Oscillator* m_osc;

  float m_modDepth;
  float m_modSignal = 0;
};
