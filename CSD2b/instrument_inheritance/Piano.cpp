#include "Piano.h"
#include <iostream>

Piano::Piano(std::string pitch) : Instrument(pitch)
{
  std::cout << "constructor Piano called " << std::endl;
}

Piano::~Piano()
{
  std::cout << "deconstructor Piano called" << std::endl;
}

void Piano::play(int sustain, int damper)
{
  std::cout << "Pitch is " << pitch << ". Pitch range for piano is A0 - C8" << std::endl;
  std::cout << "Damper pedal is " << damper << std::endl;
  std::cout << "Sustain pedal is " << sustain << std::endl;
  std::cout << "Pliiiiiiiiiing" << std::endl;
}
