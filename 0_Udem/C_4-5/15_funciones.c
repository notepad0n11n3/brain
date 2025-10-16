#include <stdio.h>
#include <stdlib.h>

void suma();  // las funciones tambi[en se declaran antes como las variables

int main(){

  suma();
}

void suma(){   // func tipo void no devuelve nada 
  int num1, num2;

  printf("Introduce un n[umero: \n");
  scanf("%d",&num1);

  printf("Introduce un n[umero: \n");
  scanf("%d",&num2);

  int resultado = num1 + num2;

  printf("La suma es: %d\n", resultado);

  return 0;
}
