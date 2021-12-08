#pragma once
#include <iostream>

class Oscillator {
  public:
    Oscillator(std::string pitch, std::string name);
    ~Oscillator();

  protected:
    std::string pitch;
    std::string name;
};
