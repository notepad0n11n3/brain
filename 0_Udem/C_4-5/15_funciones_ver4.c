#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void suma(int num1, int num2, int *resultado);

int main(){
  
  int num1, num2;

  printf("Ingrese un n[umero: \n");
  scanf("%d", &num1);

  printf("Ingrese un n[umero: \n");
  scanf("%d", &num2);

  int resultado;

  suma(num1, num2, &resultado);

  printf("\n\t La Suma es: %d\n", resultado);
  
  return 0;
}

void suma(int num1, int num2, int *resultado){
  *resultado = num1 + num2;
}
