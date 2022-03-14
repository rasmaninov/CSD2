#pragma once
#include "fxbase.h"
#include "cbuffer.h"
#include "oscillator.h"

class Chorus : public Effect
{
public:
  Chorus(float samplerate, float modDepth, float feedback, float delayInMS);
  ~Chorus();

  void applyEffect(float& input, float& outputL, float& outputR) override;
  void delayMS(float delayInSamps);
  void delaySamps(float delaySamps);
  void setFeedback(float feedback1);

protected:
  Oscillator* m_oscL;
  Oscillator* m_oscR;
  float m_modDepth;
  float m_modSignal = 0;
  float feedback;
  float feedback1;
  float samplerate;
  Cbuffer cbuffer;
  float delayInMS;
  float delayInSamps;

  float delaytime;

};
