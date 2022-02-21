#pragma once
#include <iostream>

class Effect
{
public:
  // Effect();
  Effect();
  ~Effect();
private:
  float processFrame(float sample);
};
