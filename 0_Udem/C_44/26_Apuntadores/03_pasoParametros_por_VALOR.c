#include <stdio.h>

void agregar(int a){
  a += 10;
  printf("\n\t\t Dentro de la funcion: %d", a);
}

int main(void){

  int numero;
  printf("\nIngresa un entero: ");
  scanf("%d", &numero); getchar();

  printf("\nValor antes de la funcion: %d", numero);

  agregar(numero);

  printf("\nValor despu[es de la funcion: %d", numero);

  return 0;
}
