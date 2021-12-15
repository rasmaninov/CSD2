#include "synth.h"

Synth::Synth(float midiPitch, double samplerate) : sample(0)
{
  sine.initialize(samplerate);
  setMidiPitch(midiPitch);

}

Synth::~Synth() {}

void Synth::tick()
{
  sine.tick();
  sample = sine.getSample();
}

double Synth::getSample()
{
  return sample;
}

void Synth::setMidiPitch(float pitch)
{
  // TODO check if pitch is different
  // TODO - check if pitch is in range
  midiPitch = pitch;

  double freq = mtof(midiPitch);
  std::cout << freq << std::endl;
  sine.setFrequency(freq);
}
//fm  =  2(m−69)/12(440 Hz)
double Synth::mtof(float pitch)
{
  return pow(2.0, (pitch - 69.0)/12.0) * 440;
}
