#include "circkle.h"

Circle::Circle(int size, int numSamplesDelay) :
  readH(size - numSamplesDelay - 1), writeH(0),
  size(size), numSamplesDelay(numSamplesDelay)
{
  buffer = new float[size];
}

Circle::~Circle()
{

}

void Write(float value)
{

}

void Read()
{

}

void wrapH()
{
  if(writeH == size){
    writeH = 0;
  }

  if(readH == size){
    readH = 0;
  }
}

void getDistanceRW()
{

}
