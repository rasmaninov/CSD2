#include "tremsub.h"
#include "sine.h"
#include "square.h"

Tremolo::Tremolo(float samplerate, float modFreq, float modDepth) : Effect(), m_modDepth(modDepth)
{
  m_osc = new Sine(modFreq, samplerate);
}

Tremolo::~Tremolo()
{
  delete m_osc;
  m_osc = nullptr;
}

void Tremolo::setModFreq(float modFreq)
{
  m_osc->setFrequency(modFreq);
}

void Tremolo::applyEffect(float& input, float& output){
  m_modSignal = m_osc->genNextSample() * 0.5 + 0.5;

  m_modSignal *= m_modDepth;
  m_modSignal += 1.0 - m_modDepth;

  output = input * m_modSignal;


}
