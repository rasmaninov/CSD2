#include "oscillator.h"


Oscillator::Oscillator() : Oscillator() {}

Oscillator::Oscillator(double frequency, double samplerate , double phase , double sample , double amplitude){
  std::cout << "constructor oscillator called" << std::endl;
  this -> frequency;
  this -> samplerate;
  this -> phase;
  this -> amplitude;
  this -> sample;
}

Oscillator::~Oscillator(){
  std::cout << "deconstructor oscillator called" << std::endl;

}
  Oscillator::Oscillator(){}
// Oscillator::Initialize(double phase, double sample, double amplitude){
//   this -> phase = 0;
//   this -> amplitude = 0;
//   this -> samplerate = 0;
// }
