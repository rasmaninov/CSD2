#include "instrument.h"
#include <iostream>


class Synth : public Instrument
{
public:
  Synth(std::string pitch, std::string name);
  ~Synth();

  void play(int filt, int amp);
};
