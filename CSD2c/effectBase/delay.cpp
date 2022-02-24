#include "delay.h"

Delay::Delay(float samplerate, float modDepth) : Effect(), m_modDepth(modDepth){}

Delay::~Delay() {

}

void Delay::applyEffect(float& input, float& output){
  m_modSignal = 0.5 + 0.5;

  m_modSignal *= m_modDepth;
  m_modSignal += 1.0 - m_modDepth;

  output = input * m_modSignal;

}
