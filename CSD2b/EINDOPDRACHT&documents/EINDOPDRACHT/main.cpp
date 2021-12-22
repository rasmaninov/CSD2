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
#include "melodygen.h"
#include "ui.h"


#define WRITE_TO_FILE 0


int main(int argc,char **argv)
{
  // create a JackModule instance
  JackModule jack;

  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  double samplerate = jack.getSamplerate();
  // what
  Melody mel;
  mel.MelodyGen();

  Complex complex(mel.notes[0], samplerate);
  Simple simple(mel.notes[0], samplerate);

  std::string synthOptions[2] = {"Simple", "Complex"};
      int numWaveFormOptions = 2;

      std::string synthSelection = Ui::retrieveUserSelection(synthOptions,
          numWaveFormOptions);

      std::cout << "You selected: " << synthSelection << std::endl;
      if(synthSelection == "Simple"){
        int detuneValue = 0;
        detuneValue =  Ui::retrieveValueInRange(0, 10);
        std::cout << "You chose the following value: " << detuneValue << std::endl;
      simple.detune = detuneValue;
      }

  Synth* synth= nullptr;

  if(synthSelection == "Simple"){
    synth = &simple;
  } else if (synthSelection == "Complex"){
    synth = &complex;
    }

#if WRITE_TO_FILE
    WriteToFile fileWriter("output.csv", true);

    for(int i = 0; i < 500; i++) {
      fileWriter.write(std::to_string(synth.getSample()) + "\n");
      synth->tick();
    }
#else

  float amplitude = 0.1;
  int frameCount = 0;
  int step = 1;

  //assign a function to the JackModule::onProces
  jack.onProcess = [&synth, &amplitude, &step, &frameCount, &mel, &jack](jack_default_audio_sample_t *inBuf,
    jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {
    for(unsigned int i = 0; i < nframes; i++) {
      outBuf[i] = synth->getSample() * amplitude;
      synth->tick();
      frameCount ++;
      if (frameCount == 22050){
        synth->setMidiPitch(mel.notes[step]);
        step = step + 1;
        frameCount = 0;
        if(step == 15){
          jack.end();
        }
      }

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
