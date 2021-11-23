#include "instrument.h"

Instrument::Instrument(std::string _sound){
  std::cout << "start" << std::endl;
  sound = _sound;
}
Instrument::~Instrument(){
  std::cout << "klaar" << std::endl;
}
void Instrument::play(){
  std::cout << sound << std::endl;
}
