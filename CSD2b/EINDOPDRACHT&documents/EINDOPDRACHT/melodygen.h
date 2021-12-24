#include <iostream>

class Melody {
public:
  Melody();
  ~Melody();


  void MelodyGen();
  //generation of the melody happens here
  int noteCount = 0;
  // if noteCount == 16, then melody list is done.
  int newPitch = 0;
  // pitch to put into list
  int notes[16];
  // a list of melody notes in midi
};
