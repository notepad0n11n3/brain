#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

  int resultado;
  printf("Numeros aleatorios entre 100 y 150\n");

  srand(time(NULL));

  resultado = rand() % 51; // resultado = (rand() % 51) + 100;

  printf("=> %d\n",resultado);
  printf("=> %d\n", (resultado + 100));

  
  return 0;
}
