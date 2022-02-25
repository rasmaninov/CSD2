#pragma once
#include "fxbase.h"
#include "cbuffer.h"

class Delay : public Effect
{
public:
  Delay(float samplerate, float modDepth = 1.0f);
  ~Delay();

  void applyEffect(float& input, float& output) override;


protected:
  float m_modDepth;
  float m_modSignal = 0;
  Cbuffer cbuffer;
};
