#include <stdio.h>
#include <stdlib.h>

#include "operaciones.c"

int main(){
  int o1,o2;
  int rsuma,rresta,rmult;
  float rdiv;

  printf("Introduce el operando 1: \n");
  scanf("%d", &o1);

  printf("Introduce el operando 2: \n");
  scanf("%d", &o2);

  rsuma = sumar(o1, o2);
  rresta = restar(o1, o2);
  rmult = multiplicar(o1, o2);
  rdiv = dividir(o1, o2);

  printf("Suma: %d\n", rsuma);
  printf("Resta: %d\n", rresta);
  printf("Multiplicaci[on: %d\n", rmult);
  printf("Division: %.1f\n", rdiv);
}
