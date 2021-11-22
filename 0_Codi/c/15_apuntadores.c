
/*
 *  Apuntadores son variables cuyos valores son direcciones de memoria
 */

#include <stdio.h>

int main()
{

  int a = 2;
  int *apt = &a;

  printf("%i \n", *apt);
  printf("%p \n", apt);  // imprime el valor 2 en hexadecimal 

  return 0;
}
