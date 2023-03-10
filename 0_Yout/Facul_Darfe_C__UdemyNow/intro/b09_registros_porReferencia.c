#include <stdio.h>


struct Punto2{
  float z;
  float w;
};

struct Punto{
  float x;
  float y;
  struct Punto2 p2;
};



void my_littleFunction(struct Punto *mango);


int main(int argc, char *argv[]){
  struct Punto p;

  p.x = 10.5;
  p.y = -2;

  my_littleFunction(&p);
  fprintf(stdout, "\n\t\t %f, %f, %f, %f\n",  p.x,  p.y,  p.p2.w,  p.p2.z );

  return 0;
}


void my_littleFunction(struct Punto *mango){
  mango->x = mango->x * 2;
  mango->y = 8;

  mango->p2.w = mango->p2.w * 2;
  mango->p2.z = 8;
}
