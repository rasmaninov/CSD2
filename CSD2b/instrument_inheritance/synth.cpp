#include "synth.h"

Synth::Synth(std::string pitch) : Instrument(pitch)
{
  std::cout << "constructor synth called" << std::endl;
}

Synth::~Synth(){
  std::cout << "deconstructor synth called" << std::endl;
}

void Synth::play(int filt, int amp)
{
  std::cout << filt << " filter frequency" << std::endl;
  std::cout << amp << " amp" << std::endl;
}
