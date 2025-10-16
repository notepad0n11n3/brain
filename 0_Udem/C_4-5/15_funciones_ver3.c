#include <stdio.h>
#include <stdlib.h>

int suma(int num1, int num2);

int main(){

  int num1, num2;

  printf("Ingrese un n[umero: \n");
  scanf("%d", &num1);

  printf("Ingrese un n[umero: \n");
  scanf("%d", &num2);

  int mainResultado = suma(num1, num2);

  printf("La suma es: %d\n", mainResultado);

  return 0;
}

int suma(int num1, int num2){
  int resultado = num1 + num2;
  return resultado;
}
