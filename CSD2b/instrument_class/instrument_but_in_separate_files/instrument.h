#include <iostream>

class Instrument {
  public:
    Instrument(std::string _sound);
    ~Instrument();
    void play();
    std::string sound;
};
