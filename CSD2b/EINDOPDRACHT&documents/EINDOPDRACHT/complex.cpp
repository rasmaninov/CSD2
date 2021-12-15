#include "simplesynth.h"

Simple::Simple() : Simple(0,0) {}

Simple::Simple(float midiPitch, double samplerate) : Synth(midiPitch, samplerate) {
std::cout << "con Simple" << std::endl;
}

Simple::~Simple() {
std::cout << "decon Simple" << std::endl;
}

Simple::calculate(){

}
