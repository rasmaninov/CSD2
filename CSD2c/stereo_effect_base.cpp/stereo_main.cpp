#include "jack_module.h"
#include <string>
#include <math.h>
#include <thread>
#include <unistd.h>
#include <iostream>
#include "chorus.h"
#include "sine.h"

unsigned long chunksize = 2048;
JackModule jack;
float samplerate = 44100;
Chorus chorus(samplerate, 1, 0.2, 3); //samplerate,moddepth,feedback,delayms
bool running = true;
float outbuf;

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
      chorus.processFrame(inbuffer[x], outbuf);

      outbuffer[2*x]= outbuf * 0.2; //left channel?
      outbuffer[2*x+1]= outbuf * 0.2; //right channel?
    }
    jack.writeSamples(outbuffer,chunksize*2);
  } while(running);

  return 0;
}
