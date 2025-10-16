#include <stdio.h>
                        // &  direcci[on de memoria
                        // *  el valor de lo que esta apuntando

int main(void){

  int numero = 50;
  int *p_Numero;

  printf("Dato: %i\n", numero);        // Dato
  printf("\nPosicion: %p\n", &numero); // Posici[on en memoria

  p_Numero = &numero;

  printf("\n\tValor de la variable\n");
  printf("Dato: %i\n", numero);
  printf("Dato: %i\n", *p_Numero);       // * todo lo que esta dentro de esa posici[on de memoria
                                         // sin * muestra la direcci[on de memoria en hexadecimal

  printf("\n\t Posicion de memoria \n");
  printf("Posicion: %p\n", &numero);
  printf("Posicion: %p\n", p_Numero);     // sin * muestra la direcci[on de memoria en hexadecimal

  return 0;
}
