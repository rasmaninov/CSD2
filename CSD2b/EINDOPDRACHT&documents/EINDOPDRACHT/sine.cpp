#include "sine.h"
#include "math.h"

Sine::Sine() : Sine(0,0) {}

Sine::Sine(double frequency, double samplerate) :
  Oscillator(frequency, samplerate)
{
  std::cout << "con sine" << std::endl;
}

Sine::~Sine(){
  std::cout << "decon sine" << std::endl;
}

void Sine::calcNextSample(){
  sample = sin(M_PI * 2 * phase);
}
