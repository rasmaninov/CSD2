#include "fxbase.h"

Effect::Effect(float dryWet){
  setDryWet(dryWet);
}

Effect::~Effect(){
}

float Effect::processFrame(float& input, float& outputL, float& outputR){
  applyEffect(input, outputL, outputR);
  outputL = input * wetDry + outputL * dryWet;
  outputR = input * wetDry + outputR * dryWet;
  return outputL;
  return outputR;
}

float Effect::getSample(){
  return m_sample;
}

void Effect::setDryWet(float dryWet){
  if(dryWet < 0 || dryWet > 1){
    throw "dryWet not in range [0, 1]";
  }

  this-> dryWet = dryWet;
  wetDry = 1.0f - dryWet;
}
