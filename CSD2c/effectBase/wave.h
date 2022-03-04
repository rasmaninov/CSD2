#pragma once
#include "fxbase.h"

class Waveshaper : public Effect
{
public:
  Waveshaper (float samplerate, float dryWet);
  ~Waveshaper();

  void applyEffect(float& input, float& output) override;
protected:
  float samplerate;
  float m_modDepth;
  float m_modSignal = 0;
};
