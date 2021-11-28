#include "instrument.h"
#include <iostream>

class Guitar : public Instrument
{
public:
  Guitar(std::string pitch);
  ~Guitar();

  void play(int style, int tone);

};
