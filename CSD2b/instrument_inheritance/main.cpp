#include "synth.h"
#include "Piano.h"
#include "Guitar.h"

int main()
{
  Synth biem("12", "biem");
  Piano yamaha("12", "Yamaha");
  Guitar fender("12", "fender");
  biem.play(3800, 1);
  yamaha.play(1, 0);
  fender.play(1, 0);
}
