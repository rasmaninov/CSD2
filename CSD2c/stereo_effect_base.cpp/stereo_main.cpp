#include "jack_module.h"
#include "sine.h"
#include <string>
#include <math.h>
#include <thread>
#include <unistd.h>
#include <iostream>

unsigned long chunksize = 2048;
JackModule jack;
float samplerate = 44100;
Sine sine(440, samplerate);
Sine sone(220, samplerate);
bool running = true;
//
// static void filter(){
//
// }

int main(int argc, char **argv){

  jack.init(argv[0]);
  jack.autoConnect();

  jack.setNumberOfInputChannels(2);
  jack.setNumberOfOutputChannels(2);

  float *inbuffer = new float[chunksize];
  float *outbuffer = new float[chunksize];

  do{
    jack.readSamples(inbuffer,chunksize);
    for(unsigned int x=0; x<chunksize; x++)
    {
      // ... your algorithm here
      outbuffer[2*x]= sine.genNextSample();
      outbuffer[2*x+1]= sone.genNextSample();
    }
    jack.writeSamples(outbuffer,chunksize*2);
  } while(running);

  return 0;
}
