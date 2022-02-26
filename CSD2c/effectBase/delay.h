#pragma once
#include "fxbase.h"
#include "cbuffer.h"

class Delay : public Effect
{
public:
  Delay(float samplerate, float modDepth, float feedback, float delayInMS);
  ~Delay();

  void applyEffect(float& input, float& output) override;
  void delayMS(float delayInSamps);
  void delaySamps(float delaySamps);
  void setFeedback(float feedback1);
protected:
  float m_modDepth;
  float m_modSignal = 0;
  float feedback;
  float feedback1;
  float samplerate;
  Cbuffer cbuffer;
  float delayInMS;
  float delayInSamps;
};
