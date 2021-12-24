#include "sine.h"
#include "math.h"

Sine::Sine() : Sine(0,0) {}

Sine::Sine(double frequency, double samplerate) :
  Oscillator(frequency, samplerate) {
}

Sine::~Sine(){
}

// Calculating next sample based on sample = formula
void Sine::calcNextSample(){
  sample = sin(M_PI * 2 * phase);
}
