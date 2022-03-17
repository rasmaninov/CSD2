#include "filter.h"
#include "sine.h"
#include <iostream>

Filter::Filter(float samplerate, float cutoff) : Effect(), cbuffer(4, 1)
{
  this->samplerate = samplerate;
  // delaySamps(1);
  m_osc = new Sine(1, samplerate);
}

Filter::~Filter(){
  delete m_osc;
  m_osc = nullptr;
}

    // output = ((0.5 + 0.5-cutoff) * input) + (change * (cutoff * lastSample));
void Filter::applyEffect(float& input, float& output){
  cutoff =(m_osc->genNextSample() +1) * 16;
  // std::cout << cutoff << std::endl;
  output = ((input * (0.5 + 0.5 - cutoff)) + (previousSample * cutoff));
  // prevPrevSample = previousSample;
  previousSample = input;

}
