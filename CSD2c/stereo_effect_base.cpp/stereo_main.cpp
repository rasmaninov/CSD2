#include "jack_module.h"
#include <string>
#include <math.h>
#include <thread>
#include <unistd.h>
#include <iostream>
#include "delay.h"
#include "sine.h"

unsigned long chunksize = 2048;
JackModule jack;
float samplerate = 44100;
Delay delayL(samplerate, 1, 0, 3); //samplerate,moddepth,feedback,delayms
Delay delayR(samplerate, 1, 0, 7);
bool running = true;
float outbufL;
float outbufR;

Sine sine(10, samplerate);
int main(int argc, char **argv){

  jack.init(argv[0]);
  jack.autoConnect();

  jack.setNumberOfInputChannels(1);
  jack.setNumberOfOutputChannels(2);

  float *inbuffer = new float[chunksize];
  float *outbuffer = new float[chunksize];

  do{
    jack.readSamples(inbuffer,chunksize);
    for(unsigned int x=0; x<chunksize; x++)
    {
      // ... your algorithm here
      float delaytime;
      delaytime = (sine.genNextSample() + 5);
      delayR.delayMS(delaytime);

      delayL.processFrame(inbuffer[x], outbufL);
      delayR.processFrame(inbuffer[x], outbufR);
      outbuffer[2*x]= outbufL * 0.2; //left channel?
      outbuffer[2*x+1]= outbufR * 0.2; //right channel?
    }
    jack.writeSamples(outbuffer,chunksize*2);
  } while(running);

  return 0;
}
