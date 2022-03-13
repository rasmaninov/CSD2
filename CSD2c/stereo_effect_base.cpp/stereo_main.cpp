#include "jack_module.h"
#include "sine.h"
#include <string>
#include <math.h>
#include <thread>
#include <unistd.h>
#include <iostream>

int main(int argc, char **argv){
  unsigned long chunksize = 2048;

  JackModule jack;

  jack.setNumberOfInputChannels(2);
  jack.setNumberOfOutputChannels(2);

  jack.init(argv[0]);
  float samplerate = jack.getSamplerate();

  Sine sine(440, samplerate);
  Sine sone(220, samplerate);

  float *inbuffer = new float[chunksize];
  float *outbuffer = new float[chunksize];

  jack.onProcess = [&sine, &sone, &chunksize, &jack, &inbuffer, &outbuffer]
  (jack_default_audio_sample_t* inBuf, jack_default_audio_sample_t* outBuf, jack_nframes_t nframes){
    jack.readSamples(inbuffer,chunksize);
    for(unsigned int x=0; x<chunksize; x++)
    {
      // ... your algorithm here
      outbuffer[2*x]= sine.genNextSample();
      outbuffer[2*x+1]= sone.genNextSample();
    }
    jack.writeSamples(outbuffer,chunksize*2);
  };
jack.end();
  return 0;
}
