#include "Guitar.h"
#include <iostream>

Guitar::Guitar(std::string pitch) : Instrument(pitch)
{
  std::cout << "constructor Guitar called" << std::endl;
}

Guitar::~Guitar()
{
  std::cout << "deconstructor guitar called" << std::endl;
}

void Guitar::play(int style, int tone)
{
  std::cout << "pitch is " << pitch << ". Pitch range guitar is E2 - E6" << std::endl;
  std::cout << "the style is " << style << std::endl;
  std::cout << "tone is " << tone << std::endl;
  std::cout << "grwohaaa" << std::endl;
}
