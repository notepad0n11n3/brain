
#include <stdio.h>

void saludo ()
{
  printf("Hola C[odigoFacilito\n");
  return;
}
int suma();

int main()
{
  saludo();

  printf("%i \n", suma());

  return 0;
}

int suma()
{
  int numberOne = 4;
  int numberTwo = 3;
  int re = numberOne + numberTwo;
  return re;
}
