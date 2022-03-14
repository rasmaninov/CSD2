#include "chorus.h"
#include "sine.h"

Chorus::Chorus(float samplerate, float modDepth, float feedback, float delayInMS ) : Effect(),
  m_modDepth(modDepth),
  cbuffer(4410000, 22050)
  {
  this->feedback = feedback;
  this->samplerate = samplerate;
  delayMS(delayInMS);

  m_osc = new Sine(1, samplerate);

}

Chorus::~Chorus() {
  delete m_osc;

  m_osc = nullptr;

}

void Chorus::applyEffect(float& input, float& output){

  delaytime = (m_osc->genNextSample() + 5);
  delayMS(delaytime);
  output = m_modSignal + input;

  cbuffer.write(input + output * feedback);

  m_modSignal = cbuffer.read() ;

  // m_modSignal *= m_modDepth;
  // m_modSignal += 1.0 - m_modDepth;

}

void Chorus::delayMS(float delayInMS){
  delayInSamps = delayInMS * (samplerate / 1000);

  cbuffer.setNumSamplesDelay(delayInSamps);

}

void Chorus::delaySamps(float delaySamps){
  cbuffer.setNumSamplesDelay(delaySamps);

}

void Chorus::setFeedback(float feedback1){
  this->feedback = feedback1;
}
