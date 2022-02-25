#pragma once
#include <iostream>

class Cbuffer {
public:
  Cbuffer(int size, int numSamplesDelay);
  ~Cbuffer();

  void write(float value);
  float read();

private:
  int wrapH(int head);
  int readH;
  int writeH;
  int size;
  int numSamplesDelay;
  float* buffer;


};
