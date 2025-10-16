
#include <stdio.h>

int suma();
int num3=2;

int main()
{
  int num1, num2;
  printf("Ingrese el primer n[umero: \n");
  scanf("%i", &num1);

  printf("Ingrese el segundo n[umero: \n");
  scanf("%i", &num2);

  printf("El resultado es: %i \n", suma(num1,num2));

  return 0;
}

int suma(int num1, int num2)
{
  int suma = num1 + num2 + num3;
  return suma;
}
