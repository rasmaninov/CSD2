#include "sine.h"
#include "jack_module.h"
#include <iostream>
#include "math.h"
#include "square.h"
#include "saw.h"
#include "writeToFile.h"
#include "synth.h"
#include "simplesynth.h"
#include "complex.h"


#define WRITE_TO_FILE 0

int main(int argc,char **argv)
{
  // create a JackModule instance
  JackModule jack;

  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  double samplerate = jack.getSamplerate();
  // Sine sine(440, samplerate);
  Complex synth(60, samplerate);

#if WRITE_TO_FILE
    WriteToFile fileWriter("output.csv", true);

    for(int i = 0; i < 500; i++) {
      fileWriter.write(std::to_string(synth.getSample()) + "\n");
      synth.tick();
    }
#else

  float amplitude = 0.1;
  //assign a function to the JackModule::onProces
  jack.onProcess = [&synth, &amplitude](jack_default_audio_sample_t *inBuf,
    jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    for(unsigned int i = 0; i < nframes; i++) {
      outBuf[i] = synth.getSample() * amplitude;
      synth.tick();

    }
    amplitude = 0.2;
    return 0;
  };

  jack.autoConnect();

  //keep the program running and listen for user input, q = quit
  std::cout << "\n\nPress 'q' when you want to quit the program.\n";
  bool running = true;
  while (running)
  {
    switch (std::cin.get())
    {
      case 'q':
        running = false;
        jack.end();
        break;
    }
  }
  #endif
  //end the program
  return 0;
} // main()
