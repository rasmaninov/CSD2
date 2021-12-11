#include "square.h"
#include "math.h"

Square::Square(double frequency, double samplerate) : frequency(frequency),
amplitude(1.0), phase(0), sample(0), samplerate(samplerate)
{
  std::cout << "constructor Square called" << std::endl;
}

Square::~Square(){
  std::cout << "deconstructor Square called" << std::endl;
}

float Square::getSample() {
  return sample;
}

// void Square::calculate(){
//
// }

void Square::tick(){
  phase += frequency / samplerate;

  if(phase > 1) phase -= 1.0;
  if(phase < 0.5) {
      sample = 1.0;
    } else {
      sample = -1.0;
    }

  sample *= amplitude;
}

void Square::setFrequency(float frequency)
{
  this->frequency = frequency;
}

float Square::getFrequency()
{
  return frequency;
}
