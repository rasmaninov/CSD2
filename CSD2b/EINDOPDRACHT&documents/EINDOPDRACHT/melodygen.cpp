#include "melodygen.h"
#include <cstdlib>
Melody::Melody(){
  std::cout << "con mel" << std::endl;
}

Melody::~Melody(){
  std::cout << "decon mel" << std::endl;
}

void Melody::MelodyGen(){
  for (unsigned int i = 0; i < 16; i++){
    newPitch = (rand() % 60 + 20)%12 + 48;
    notes[i] = newPitch;
    noteCount = noteCount + 1;
  }
}
