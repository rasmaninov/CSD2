#include "instrument.h"
#include <iostream>

class Guitar : public Instrument
{
public:
  Guitar(std::string pitch, std::string name);
  ~Guitar();

  void play(int style, int tone);

};
