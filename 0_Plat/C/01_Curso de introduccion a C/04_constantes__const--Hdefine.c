#include <stdio.h>

#define COSTHOTDOD_NEWDES 100                     /// las CONSTANTES con define NO LLEVAN ; AL FINAL 
#define GOROGORONEE 3.8
#define PIZZACOST 1.5

                
                            // const se usa m]as para declarar constantes dentro de funciones, al ser una constante usar[a menos espacio en memoria <3
const int COSTHOTDOG = 100;             ///las constantes con 'const' SI LLEVAN  ;  al final
const float TOTAL = 100.33;
const char GORO = '\n';

int main(){

  float costoPizzas;
  float numberOfSlices=3;

  printf("%f pizzacost\t",PIZZACOST); printf("\t%f numberOfSlices\n",numberOfSlices);
  costoPizzas = PIZZACOST * numberOfSlices;

  printf("Costo toal: %.2f\n",costoPizzas);
  printf("%c",GORO);

  return 0;
}
