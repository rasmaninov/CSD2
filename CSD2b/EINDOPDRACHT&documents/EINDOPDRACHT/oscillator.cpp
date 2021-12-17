#include "oscillator.h"

Oscillator::Oscillator(double frequency, double samplerate) :
  phase(0), sample(0), amplitude(1.0) {
  this -> frequency = frequency;
  this -> samplerate = samplerate;
  std::cout << "constructor oscillator called" << std::endl;

}

Oscillator::~Oscillator(){
  std::cout << "deconstructor oscillator called" << std::endl;

}

void Oscillator::initialize(double samplerate){
  this->samplerate=samplerate;
}

double Oscillator::getSample(){
  return sample;
}

void Oscillator::tick() {
  phase += frequency / samplerate;

  if(phase > 1) phase -= 1.0;

  calcNextSample();
  sample *= amplitude;
}

void Oscillator::setFrequency(double frequency) {
  this-> frequency = frequency;
}

double Oscillator::getFrequency() {
  return frequency;
}
