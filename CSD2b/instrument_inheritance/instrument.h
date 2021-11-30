#pragma once
#include <iostream>

class Instrument {
  public:
    Instrument(std::string pitch, std::string name);
    ~Instrument();

    // void play(int filt, int amp);

protected:
  std::string pitch;
  std::string name;
};
