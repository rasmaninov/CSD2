#include <iostream>

class Instrument {
  public:
    Instrument();
    ~Instrument();
    void play();
    std::string sound;
};

Instrument::Instrument(){
  sound = "Ratatataaaa";
}
Instrument::~Instrument(){
  std::cout <<"klaar"<<std::endl;
}
void Instrument::play(){
  std::cout << sound << std::endl;
}

int main()
{
  Instrument pipa; //create object
  Instrument boom;
  boom.sound = "biem";
  pipa.play();
  boom.play();
}
