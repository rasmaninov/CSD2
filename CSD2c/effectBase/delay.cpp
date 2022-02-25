#include "delay.h"

Delay::Delay(float samplerate, float modDepth) : Effect(),
  m_modDepth(modDepth),
  cbuffer(44100, 44099)
{

}

Delay::~Delay() {

}

void Delay::applyEffect(float& input, float& output){
  cbuffer.write(input);
  m_modSignal = 0.5 + 0.5;

  m_modSignal *= m_modDepth;
  m_modSignal += 1.0 - m_modDepth;

  output = cbuffer.read() * m_modSignal;

}
