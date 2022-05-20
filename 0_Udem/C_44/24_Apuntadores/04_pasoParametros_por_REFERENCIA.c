#include <stdio.h>

                  // SI se MODIFICA el valorVARIABLE. al pasar a la funci[on por REFERENCIA    & * 

void agregar(int *a){

  *a += 10;
  printf("\n\t\tValor DURANTE LA FUNCI[ON: %d", *a);
}

int main(){

  int numero;
  printf("\nIngrese un entero: ");
  scanf("%d", &numero); getchar();

  printf("\nValor antes de la funci[on: %d", numero);

  agregar(&numero);

  printf("\nValor despu[es de la fucni[on: %d", numero);

  return 0;
}
