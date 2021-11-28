#include "synth.h"

Synth::Synth(std::string pitch) : Instrument(pitch)
{
  std::cout << "Constructor synth called" << std::endl;
}

Synth::~Synth(){
  std::cout << "Deconstructor synth called" << std::endl;
}

void Synth::play(int filt, int amp)
{
  std::cout << "pitch is " << pitch << ". Pitch range for synth is E0 - E6" << std::endl;
  std::cout << "Filter frequency is " << filt << " Khz" << std::endl;
  std::cout << "Amplitude is : " << amp << std::endl;
  std::cout << "WUuuhaooaaaaah" << std::endl;
}
