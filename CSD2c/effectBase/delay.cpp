#include "delay.h"

Delay::Delay(float samplerate, float modDepth, float feedback, float delayInMS ) : Effect(),
  m_modDepth(modDepth),
  cbuffer(441000, 22050)
{
  this->feedback = feedback;
  this->samplerate = samplerate;
  delayMS(delayInMS);
}

Delay::~Delay() {
}

void Delay::applyEffect(float& input, float& output){
  output = m_modSignal + input;

  cbuffer.write(input + output * feedback);
  m_modSignal = cbuffer.read();

  m_modSignal *= m_modDepth;
  m_modSignal += 1.0 - m_modDepth;

}

void Delay::delayMS(float delayInMS){
  delayInSamps = delayInMS * (samplerate / 1000);


  cbuffer.setNumSamplesDelay(delayInSamps);

}
