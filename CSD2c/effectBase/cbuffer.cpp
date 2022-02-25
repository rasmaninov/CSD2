#include "cbuffer.h"
// initializer list = values after colon
Cbuffer::Cbuffer(int size, int numSamplesDelay) :
  readH(size - numSamplesDelay),
  writeH(0),
  size(size),
  numSamplesDelay(numSamplesDelay)
{
  // creating buffer thats sized[size]
  buffer = new float[size];
  // initializing every value in buffer array
  for(int i =0; i < size; i++){
    buffer[i] = 0;
  }

}

Cbuffer::~Cbuffer(){
  // delete dynamic array
  delete [] buffer;
}

void Cbuffer::write(float value){

  buffer[writeH++] = value;
  writeH = wrapH(writeH);
}

float Cbuffer::read(){
  float value = buffer[readH++];
  readH = wrapH(readH);
  return value;
}

int Cbuffer::wrapH(int head){
  if(head >= size) head -= size;
  return head;
}
