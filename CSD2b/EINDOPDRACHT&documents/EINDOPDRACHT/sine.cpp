#include "sine.h"
#include "math.h"

Sine::Sine(double frequency, double samplerate) : frequency(frequency),
amplitude(1.0), phase(0), sample(0), samplerate(samplerate)
{
  std::cout << "constructor Sine called" << std::endl;
}

Sine::~Sine(){
  std::cout << "deconstructor Sine called" << std::endl;
}

float Sine::getSample() {
  return sample;
}

// void Sine::calculate(){
//
// }

void Sine::tick(){
  phase += frequency / samplerate;

  sample = sin(M_PI * 2 * phase) * amplitude;
  if(phase > 1) phase -= 1.0;
}

void Sine::setFrequency(float frequency)
{
  this->frequency = frequency;
}

float Sine::getFrequency()
{
  return frequency;
}
