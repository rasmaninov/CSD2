#include "instrument.h"
#include <iostream>

class Piano : public Instrument
{
public:
  Piano(std::string pitch, std::string name);
  ~Piano();

  void play(int sustain, int damper);
};
