#pragma once
#include <iostream>

class Effect
{
public:

  Effect(float dryWet = 0.5);
  virtual ~Effect();

  float processFrame(float& input, float& outputL, float& outputR);

  float getSample();
  void setDryWet(float dryWet);

protected:

  virtual void applyEffect(float& input, float& outputL, float& outputR) = 0;

private:
  float dryWet;
  float wetDry;
  float m_sample;

};
