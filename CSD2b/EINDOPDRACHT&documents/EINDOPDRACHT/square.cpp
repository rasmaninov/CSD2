#include "square.h"
#include "math.h"

Square::Square() : Square(0,0){}

Square::Square(double frequency, double samplerate) : Oscillator(frequency, samplerate)
{
  std::cout << "constructor Square called" << std::endl;
}

Square::~Square(){
  std::cout << "deconstructor Square called" << std::endl;
}

void Square::calcNextSample(){
  if(phase < 0.5) {
    sample = 1.0;
  } else {
    sample = -1.0;
  }
}
