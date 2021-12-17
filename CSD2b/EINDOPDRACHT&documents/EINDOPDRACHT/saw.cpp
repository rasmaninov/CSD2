#include "saw.h"
#include "math.h"

Saw::Saw() : Saw(0,0) {}

Saw::Saw(double frequency, double samplerate) :
  Oscillator(frequency, samplerate)
{
  std::cout << "constructor Saw called" << std::endl;
}

Saw::~Saw(){
  std::cout << "deconstructor Saw called" << std::endl;
}

void Saw::calcNextSample(){
sample = phase * 2.0 - 1.0;
}
