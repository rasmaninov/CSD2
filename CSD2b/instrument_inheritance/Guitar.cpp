#include "Guitar.h"
#include <iostream>

Guitar::Guitar(std::string pitch, std::string name) : Instrument(pitch, name)
{
  std::cout << "constructor " << name << " called " << std::endl;
}

Guitar::~Guitar()
{
  std::cout << "deconstructor "<< name << " called" << std::endl;
}

void Guitar::play(int style, int tone)
{
  std::cout << "Pitch is " << pitch << ". Pitch range guitar is E2 - E6, "
  << "the style is " << style  << ", tone is " << tone << std::endl;
  std::cout << "Grwohaaa" << std::endl;
}
