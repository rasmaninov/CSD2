#include <iostream>


float linMap(float x,float x0,float x1,float y0,float y1){
  return y0 + (x - x0) * ((y1 - y0)/(x1-x0));

}

float linInter(float x, float y0, float y1){
  return linMap(x, 0, 1, y0, y1);
}

int main(){
  for(float i = 0; i < 100; i++){
    std::cout << linInter(i/100, 2, 4) << std::endl;

  }
}
