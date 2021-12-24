#include "square.h"
#include "math.h"

Square::Square() : Square(0,0){}

Square::Square(double frequency, double samplerate) : Oscillator(frequency, samplerate) {
}

Square::~Square(){
}

// calculating next sample based on if statement
void Square::calcNextSample(){
  if(phase < 0.5) {
    sample = 1.0;
  } else {
    sample = -1.0;
  }
}
