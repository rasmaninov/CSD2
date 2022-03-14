#include "chorus.h"
#include "sine.h"

Chorus::Chorus(float samplerate, float modDepth, float feedback, float delayInMS ) : Effect(),
  m_modDepth(modDepth),
  cbuffer(4410000, 22050)
  {
  this->feedback = feedback;
  this->samplerate = samplerate;
  delayMS(delayInMS);

  m_oscL = new Sine(1, samplerate);
  m_oscR = new Sine(1, samplerate);

}

Chorus::~Chorus() {
  delete m_oscL;
  delete m_oscR;

  m_oscL = nullptr;
  m_oscR = nullptr;

}

void Chorus::applyEffect(float& input, float& outputL, float& outputR){

  delaytime = (m_oscL->genNextSample() + 5);
  delayMS(delaytime);
  outputL = m_modSignal + input;

  delaytime = (m_oscR->genNextSample() + 5);
  delayMS(delaytime);
  outputR = input * m_modSignal;

  cbuffer.write(input + (outputL) * feedback);

  m_modSignal = cbuffer.read() ;

  m_modSignal *= m_modDepth;
  m_modSignal += 1.0 - m_modDepth;

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
