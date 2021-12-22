#include <iostream>

class Melody {
public:
  Melody();
  ~Melody();
  void MelodyGen();

  int noteCount = 0;
  int newPitch = 0;

  int notes[16];
};
