#include "oscillator.h"

Oscillator::Oscillator(std::string pitch, std::string name){
  std::cout << "Constructor called" << std::endl;
  this->pitch = pitch;
  this->name = name;

}

Oscillator::~Oscillator(){
  std::cout << "Deconstructor called" << std::endl;
}
