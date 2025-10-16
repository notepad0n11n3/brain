

// FUNCION POR REFERENCIA       LLAMADA POR REFERENCIA

// /*
#include <stdio.h>

void kubo(int *n);
int main()
{
  int num = 5;
  printf("Valor original %i \n", num);
  kubo(&num);
  printf("El nuevo valor %i \n", num);

  return 0;
}
void kubo(int *n)
{
  *n = *n * *n * *n;
}
// */

//  funcion por valor    LLAMADA POR VALOR
#include <stdio.h>
int cubo(int n);

int main()
{
  int num = 5;
  printf("Valor original %i \n", num);
  num = cubo(num);
  printf("El nuevo valor %i \n", num);
  return 0;
}

int cubo(int n)
{
  return n * n * n;

}
