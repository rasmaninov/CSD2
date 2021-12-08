/*2.  optionele stappen voor wie opnieuw wil beginnen aan de eindopdracht
         - Herstart met de eindopdracht --> gebruik nu de code uit session_4/00_sineSawSquare
         - Voeg de base class Oscillator toe, laat Sine, Saw, Square hiervan overerven
         - Verplaats de generieke code uit de subclasses naar de base class
         - werk met een calculate en tick functie
         */
#include "oscillator.h"
#include "jack_module.h"
#include <thread>
//jackd -d coreaudio
#include "sine.h"
#include "square.h"

int main(int argc, char **argv){
  Oscillator one("36", "one");
  // create a JackModule instance
  JackModule jack;

  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  double samplerate = jack.getSamplerate();
  Sine sine(220, samplerate);
  Square square(220,samplerate);

  float amplitude = 0.15;
  //assign a function to the JackModule::onProces
  jack.onProcess = [&square, &amplitude](jack_default_audio_sample_t *inBuf,
    jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    for(unsigned int i = 0; i < nframes; i++) {
      outBuf[i] = square.getSample() * amplitude;
      square.tick();
    }
    amplitude = 0.5;
    return 0;
  };


  jack.autoConnect();

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



}
