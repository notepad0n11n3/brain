#include <stdio.h>
                        // &  direcci[on de memoria
                        // *  el valor de lo que esta apuntando

int main(void){

  int a = 22;
  int b = 99;

  //  Declaramos un apuntador a la referencia de las variables
  int *apuntador_a = &a;
  int *apuntador_b = &b;

  printf("El valor de a es: %d\n",a);
  printf("La ubicaci[on en memoria del apuntador es: %p\n", apuntador_a);

  //  Cambio de valorVariables por apuntador
  *apuntador_a = 1234;

  // Nuevo valor de la variable a la que apuntaba

  printf("El valor de a es: %d\n",a);
  printf("La ubicaci[on en memoria del apuntador es: %p\n", apuntador_a);

  return 0;
}
