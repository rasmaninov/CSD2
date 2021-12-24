#include "oscillator.h"

Oscillator::Oscillator(double frequency, double samplerate) :
  phase(0), sample(0), amplitude(1.0) {
  this -> frequency = frequency;
  this -> samplerate = samplerate;
}

Oscillator::~Oscillator(){
}

// initializing the oscillator
void Oscillator::initialize(double samplerate){
  this->samplerate=samplerate;
}

// getting the sample
double Oscillator::getSample(){
  return sample;
}

// calculating the next sample of the oscillator
void Oscillator::tick() {
  phase += frequency / samplerate;
  if(phase > 1) phase -= 1.0;
  calcNextSample();
  sample *= amplitude;
}

// set the oscillator frequency
void Oscillator::setFrequency(double frequency) {
  this-> frequency = frequency;
}

// get the oscillator frequency
double Oscillator::getFrequency() {
  return frequency;
}
