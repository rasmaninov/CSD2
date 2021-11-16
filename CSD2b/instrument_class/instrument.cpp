#include <iostream>

class Instrument {
  public:
    Instrument(std::string _sound);
    ~Instrument();
    void play();
    std::string sound;
};

Instrument::Instrument(std::string _sound){
  sound = _sound;
}
Instrument::~Instrument(){
  std::cout << "klaar" <<std::endl;
}
void Instrument::play(){
  std::cout << sound << std::endl;
}

int main()
{
  Instrument pipa("biem");
  pipa.play();
}
