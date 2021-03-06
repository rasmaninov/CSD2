#include "tremsub.h"
#include "writeToFile.h"
#include "jack_module.h"
#include "sine.h"
#include "delay.h"
#include "wave.h"
#include <iostream>

#define WRITE_TO_FILE 0

#define WRITE_NUM_SAMPLES 44100

int main(int argc, char **argv) {

  // create a JackModule instance
  JackModule jack;

  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  float samplerate = jack.getSamplerate();
  // instantiate tremolo effect
  Tremolo tremolo(samplerate, 10, 0.9);
  // instantiate delay effect
  Delay delay(samplerate, 0.99, 0.99, 200);
  // instantiate waveshaper Effect
  Waveshaper wave(samplerate, 1);
  float outbuf1;
  float x = 0;
  Sine sine(440, samplerate);

    // assign a function to the JackModule::onProces
    jack.onProcess = [&sine, &tremolo, &delay, &wave, &outbuf1](jack_default_audio_sample_t* inBuf,
      jack_default_audio_sample_t* outBuf, jack_nframes_t nframes) {
  // #endif
      for(unsigned int i = 0; i < nframes; i++) {
        // outBuf[i] = sine.genNextSample();
        tremolo.processFrame(inBuf[i], outbuf1);
        delay.processFrame(outbuf1, outBuf[i]);
        // wave.processFrame(inBuf[i], outBuf[i]);
      }
      return 0;
    };

    jack.autoConnect();

    //keep the program running and listen for user input, q = quit
    std::cout << "\n\nPress 'q' when you want to quit the program."
                "\nPress 'c' when you want to change the delaytime in milliseconds"
                "\nPress 's' when you want to change the delaytime in samples"
                "\nPress 'f' when you want to change the feedback amount"
                "\nPress 'd' when you want to change the delay dry/wet setting"
                "\nPress 't' when you want to change the tremolo dry/wet setting\n";
    // boolean is used to keep program running / turn it off
    bool running = true;
    while (running)
    {
      switch (std::cin.get())
      {
        case 'q':
          running = false;
          jack.end();
          break;
        case 'c':
          std::cout << "change delaytime in MS [1- 9999]" << std::endl;
          x = 0;
          std::cin >> x;
          if(x < 10000 && x > 0){
            delay.delayMS(x);
            break;
          } else {
            std::cout << "nah bruh too big" << std::endl;
          }
        case 's':
          std::cout << "change delaytime in samples [1- 440999]" << std::endl;
          x = 0;
          std::cin >> x;
          if (x < 441000 && x > 0 ){
            delay.delaySamps(x);
            break;
          } else {
            std::cout << "out of bounds" << std::endl;
          }


        case 'f':
          std::cout << "change feedback [0. - 1.]" << std::endl;
          x = 0;
          std::cin >> x;
          if (x < 1 && x >= 0 ){
            delay.setFeedback(x);
            break;
          } else {
            std::cout << "out of bounds" << std::endl;
          }


        case 'd':
          std::cout << "change dry/wet delay [0. - 1.]" << std::endl;
          x = 0;
          std::cin >> x;
          if (x < 1 && x >= 0 ){
            delay.setDryWet(x);
            break;
          } else {
            std::cout << "out of bounds" << std::endl;
          }


        case 't':
          std::cout << "change dry/wet tremolo [0. - 1.]" << std::endl;
          x = 0;
          std::cin >> x;
          if (x < 1 && x >= 0 ){
            tremolo.setDryWet(x);
            break;
          } else {
            std::cout << "out of bounds" << std::endl;
          }



        }
    }

    //end the program
    return 0;

  } // main()
