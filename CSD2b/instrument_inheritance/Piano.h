#include "instrument.h"
#include <iostream>

class Piano : public Instrument
{
public:
  Piano(std::string pitch);
  ~Piano();

  void play(int sustain, int damper);
};
