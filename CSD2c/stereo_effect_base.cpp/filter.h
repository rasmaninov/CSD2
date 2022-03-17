#pragma once
#include "fxbase.h"
#include "cbuffer.h"
#include "oscillator.h"


class Filter : public Effect
{
public:
  Filter(float samplerate, float cutoff);
  ~Filter();

  void applyEffect(float& input, float& output) override;
  void delaySamps(float delaySamps);

protected:
  float samplerate;
  Cbuffer cbuffer;
  float delayInSamps;
  float previousSample;
  float prevPrevSample;
  float cutoff;
  Oscillator* m_osc;
};
