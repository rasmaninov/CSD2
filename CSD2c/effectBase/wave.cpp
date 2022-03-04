#include "wave.h"

Waveshaper::Waveshaper(float samplerate, float dryWet){
 this->samplerate = samplerate;
}

Waveshaper::~Waveshaper(){

}

void Waveshaper::applyEffect(float& input, float& output){
  m_modSignal = 0.5 + 0.5;

  m_modSignal *= m_modDepth;
  m_modSignal += 1.0 - m_modDepth;

  output = input * m_modSignal;


}
