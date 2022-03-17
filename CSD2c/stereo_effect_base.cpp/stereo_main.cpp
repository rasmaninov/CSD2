#include "jack_module.h"
#include <string>
#include <math.h>
#include <thread>
#include <unistd.h>
#include <iostream>
#include "chorus.h"
#include "sine.h"
#include "filter.h"
#include "saw.h"

unsigned long chunksize = 2048;
JackModule jack;
float samplerate = 44100;
// Chorus chorusL(samplerate, 1, 0, 3); //samplerate,moddepth,feedback,modSpeed
// Chorus chorusR(samplerate, 1, 0, 7);
Filter filter(samplerate, 0.5);
bool running = true;
Saw saw(220, samplerate);
float throughbuf1;

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
      // chorusL.processFrame(inbuffer[x], outbuffer[2*x]);
      // chorusR.processFrame(inbuffer[x], outbuffer[2*x+1]);
      throughbuf1 = saw.genNextSample();

      filter.processFrame(throughbuf1, outbuffer[2*x]);
      filter.processFrame(throughbuf1, outbuffer[2*x+1]);
    }
    jack.writeSamples(outbuffer,chunksize*2);
  } while(running);

  return 0;
}
