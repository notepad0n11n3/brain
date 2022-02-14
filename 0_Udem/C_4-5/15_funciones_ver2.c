#include <stdio.h>
#include <stdlib.h>

void suma(int num1, int num2);   // Las funciones tambi[en se declaran como las variables

int main(){
  int num1, num2;

  printf("Ingrese un n[umero: \n");
  scanf("%d", &num1);

  printf("Ingrese un n[umero: \n");
  scanf("%d", &num2);

  suma(num1, num2);

  return 0;
}

void suma(int num1, int num2){  // func tipo void, no devuelve nada

  int resultado = num1 + num2;
  printf("La suma es: %d\n", resultado);
}
