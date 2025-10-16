#include <stdio.h>
                        // &  direcci[on de memoria
                        // *  el valor de lo que esta apuntando

int main(void){

  int numero=3;

  printf("%d",numero);
  printf("%p",&numero);      //  & indica la posici[on de memoria d[onde se va a guardar nuestro dato         %p   p de position ?!

  int hello = 100;

  int *puntero_hello = &hello;     //   *   apuntador  a  espacio de memoria & 

//tipoData *nombre_Apuntador;

  char *hola1, *hola2;
  float *hi1, hi2;

  return 0;
}
