#include "complex.h"

Complex::Complex() : Complex(0,0) {}

Complex::Complex(float midiPitch, double samplerate) : Synth(midiPitch, samplerate) {
std::cout << "con Complex" << std::endl;
}

Complex::~Complex() {
std::cout << "decon Complex" << std::endl;
}


void Complex::calculate(){

}

void Complex::updateFreq(double freq) {

}
