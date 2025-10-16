

  // UNA FUNCION RECURSIVA TIENE LA CAPACIDAD DE LLAMARSE A SI MISMA

#include <stdio.h>

long Factorial(long numero);

int main()
{

  int numero;
  printf("ingresa un n[umero\n");
  scanf("%i",&numero);

  for( int i = 0; i <= numero; i++)
  {
    printf("%ld \n", Factorial(i) );
  }

  return 0;
}

long Factorial( long numero )
{
  if ( numero <= 1 )
  {
    return 1;
  }else{
    return( numero * Factorial(numero-1) );  // AC[A SE VUELVE A LLAMAR LA FUNCIO A SI MISMA :)
  }
}

/*
 *  Ejemplo del Factorial de Un n[umero
 *    5! = 5*4*3*2*1   [o   5*4!   ===   120
 *    4! = 4*3*2*1     [o   4*3!   ===   24
 *    3! = 3*2*1       [o   3*2!   ===   6
 *    2! = 2*1         [o   2*1!   ===   2
 *    1! = 1
 *    0! = 1
 *
 *        de abajo pa arriba men, easy :)
 */
