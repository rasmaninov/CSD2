#include "saw.h"
#include "math.h"

// initializing the saw
Saw::Saw() : Saw(0,0) {}


Saw::Saw(double frequency, double samplerate) :
  Oscillator(frequency, samplerate) {
}

Saw::~Saw(){
}

// calculating the sample based on sample = formula
void Saw::calcNextSample(){
sample = phase * 2.0 - 1.0;
}
