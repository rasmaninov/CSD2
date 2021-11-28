#include "instrument.h"
#include <iostream>


class Synth : public Instrument
{
public:
  Synth(std::string pitch);
  ~Synth();

  void play(int filt, int amp);
};
