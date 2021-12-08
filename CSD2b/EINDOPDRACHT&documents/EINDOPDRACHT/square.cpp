#include "square.h"
#include "math.h"

Square::Square(float frequency, double samplerate) : frequency(frequency),
  amplitude(1.0), phase(0), sample(0), samplerate(samplerate)
{
  std::cout << "Square - constructor\n";
}



Square::~Square() {
  std::cout << "Square - destructor\n";
}


float Square::getSample() {
  return sample;
}

void Square::tick() {
  // NOTE 1. - frequency / SAMPLERATE can be implemented in a more efficient way
  // NOTE 2. - still need todo 'something' with the phase, see 04_sin_function
  phase += frequency / samplerate;
  if(phase > 1) phase -= 1.0;
  if(phase < 0.5) {
    sample = 1.0;
  } else {
    sample = -1.0;
  }
  sample *= amplitude;
}

//getters and setters
void Square::setFrequency(float frequency)
{
  // TODO add check to see if parameter is valid
  this->frequency = frequency;
}

float Square::getFrequency()
{
  return frequency;
}
