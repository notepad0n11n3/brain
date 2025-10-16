#include <stdio.h>

int main(){

  int user_number=0, resultado=0, contador=0;

  printf("Ingrese el numero para sumar:\n");
  scanf("%d",&user_number); getchar();

  while( contador <= user_number ){
    resultado += contador;
    contador++;
  }

  printf("La suma de 0 hasta %d es: %d\n", user_number, resultado);

  return 0;
}
