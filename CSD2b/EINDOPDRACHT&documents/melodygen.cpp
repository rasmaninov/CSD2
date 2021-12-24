#include "melodygen.h"
#include <cstdlib>

Melody::Melody(){
}

Melody::~Melody(){
}

// generating a melody list based on pure randomness
void Melody::MelodyGen(){
  for (unsigned int i = 0; i < 16; i++){
    newPitch = (rand() % 60 + 20)%12 + 48;
    notes[i] = newPitch;
    noteCount = noteCount + 1;
  }
}
