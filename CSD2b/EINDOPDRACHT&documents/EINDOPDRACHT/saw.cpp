#include "saw.h"
#include "math.h"

Saw::Saw(double frequency, double samplerate) : frequency(frequency),
amplitude(1.0), phase(0), sample(0), samplerate(samplerate)
{
  std::cout << "constructor Saw called" << std::endl;
}

Saw::~Saw(){
  std::cout << "deconstructor Saw called" << std::endl;
}

float Saw::getSample() {
  return sample;
}


void Saw::tick(){
  phase += frequency / samplerate;

  if(phase > 1) phase -= 1.0;
//todo: saw formula
 sample = phase * 2.0 - 1.0;
  sample *= amplitude;
}

void Saw::setFrequency(float frequency)
{
  this->frequency = frequency;
}

float Saw::getFrequency()
{
  return frequency;
}
