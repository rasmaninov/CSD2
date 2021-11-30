#include "instrument.h"

Instrument::Instrument(std::string pitch, std::string name){
  std::cout << "Constructor called " << std::endl;
 this->pitch = pitch;
 this-> name = name;

}

Instrument::~Instrument(){
  std::cout << "Deconstructor called" << std::endl;
}
