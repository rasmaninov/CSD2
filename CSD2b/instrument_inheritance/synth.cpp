#include "synth.h"

Synth::Synth(std::string pitch, std::string name) : Instrument(pitch, name)
{
  std::cout << "constructor " << name << " called " << std::endl;
}

Synth::~Synth(){
  std::cout << "Deconstructor " << name << " called" << std::endl;
}

void Synth::play(int filt, int amp)
{
  std::cout << "pitch is " << pitch << ". Pitch range for synth is E0 - E6"
  << "Filter frequency is " << filt << " Khz" 
  << "Amplitude is : " << amp << std::endl;
  std::cout << "WUuuhaooaaaaah" << std::endl;
}
