#include "sine.h"
#include "math.h"

Sine::Sine() : Sine(0,0) {}

Sine::Sine(double frequency, double samplerate) :
  Oscillator(frequency, samplerate)
{
  std::cout << "Sine - constructor" << std::endl;
}

Sine::~Sine(){
  std::cout << "deconstructor Sine called" << std::endl;
}

void Sine::calcNextSample(){
  sample = sin(M_PI * 2 * phase);
  sample *= amplitude;
}
