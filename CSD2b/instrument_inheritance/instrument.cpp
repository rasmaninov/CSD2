#include "instrument.h"

Instrument::Instrument(std::string pitch){
  std::cout << "Constructor called " << std::endl;
 this->pitch = pitch;

}

Instrument::~Instrument(){
  std::cout << "Deconstructor called" << std::endl;
}
