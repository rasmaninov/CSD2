#include <iostream>

class Circle
{
public:
  Circle(int size, int numSamplesDelay);
  ~Circle();

  void Write(float value);
  void Read();

protected:

  int size;
  int numSamplesDelay;

  int readH;
  int writeH;

  void wrapH();
  void getDistanceRW();

  float* buffer;
};
