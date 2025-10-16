/*
 *  Ciclo Do While en C
 */

#include <stdio.h>

int main()
{
  int contador;

  do{
    printf("%i\n", contador);
    contador++;
  }while( contador  <= 10 );

  printf("%i\n",contador);

  return 0;
}
