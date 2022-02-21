#include <stdio.h>

int main(){

  int factorial=1, suma=0, cantidadFactorial;

  printf("Ingrese la cantidad de factoriales a sumar:\n");
  scanf("%d",&cantidadFactorial); getchar();

  for(int i=1; i<=cantidadFactorial; i++){
    factorial *= i;
    suma += factorial;
  }

  printf("La suma de factoriales es: %d\n",suma);

  return 0;
}
