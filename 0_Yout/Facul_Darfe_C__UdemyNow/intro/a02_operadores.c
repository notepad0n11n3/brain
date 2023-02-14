#include <stdio.h>

int main(void){

  short primero, segundo;
  float tercero;

  primero = 15;
  segundo = 2;
  tercero = primero / segundo;    //compila normal, solo es una advertencia :)

  fprintf(stdout, "\n%f\n", tercero);

  return 0;
}
