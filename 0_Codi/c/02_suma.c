#include <stdio.h>

int main()
{
  int num1, num2;
  int resultado;

  printf("ingrese el primer valor\n\t\t");
  scanf("%d",&num1); //* como read en bash, %d espera un entero, &mun1 ingresa el dato en num1
  printf("Ingrese el segundo numero:...");
  scanf("%d",&num2);

  resultado = num1 + num2;
  /*
  resultado = num1 - num2;
  resultado = num1 * num2;
  resultado = num1 / num2;
   */

  printf("\tEl resultado de la suma es: %d\n", resultado);  //* %d sera el sitio para la variable resutlado, \n salto de linea
  return 0;

}
