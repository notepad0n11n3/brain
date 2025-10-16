#include <stdio.h>
#include <math.h>

                //  ::: gcc 17_raiz_cuadrada.c -lm
int main(){
  int numero;
  float raizCuadrada;

  printf("Escribe un n[umero:\n");
  scanf("%d",&numero);

  if(numero>=0){
    raizCuadrada = sqrt(numero);   // sqrt(nuermo);    math.h
    printf("La raiz cuadrada de %d es: %.2f\n",numero,raizCuadrada);
  }else {
    printf("El n[umero tiene raiz imaginaria\n");
  }
  return 0;
}
