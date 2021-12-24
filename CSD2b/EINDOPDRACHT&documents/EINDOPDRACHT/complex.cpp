#include "complex.h"
#include <string>

Complex::Complex() : Complex(0,0) {}


Complex::Complex(float midiPitch, double samplerate) : Synth(midiPitch, samplerate) {

  for(int i = 0; i < 8; i++){
    oscs[i].initialize(samplerate);
  }
  setMidiPitch(midiPitch);
}

Complex::~Complex() {

}

void Complex::calculate(){
  for(int i = 0; i < 8; i++){
    oscs[i].tick();
    sample  += oscs[i].getSample() *0.01;
  }
}

void Complex::updateFreq(double freq) {
  for(int i = 0; i < 8; i++){
    oscs[i].setFrequency(freq * ratios[i]);
  }

}
