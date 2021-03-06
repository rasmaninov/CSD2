#include "tremolo.h"
#include "sine.h"

Tremolo::Tremolo(float freq, int samplerate)
{
  osc = new Sine(freq, samplerate);
}

Tremolo::~Tremolo()
{
  delete osc;
  osc = nullptr;
}

void Tremolo::setModFreq(float freq)
{
  osc->setFrequency(freq);
}

float Tremolo::processFrame(float sample)
{

  modSignal = (osc->genNextSample() +1.0f) * 0.5f;

  return modSignal;
}
