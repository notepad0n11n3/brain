#include <stdio.h>
#include <stdlib.h>


int main(){
  float x89p[5];
  float suma = 0;

  for(int i=0; i<5; i++){
    printf("Introduce la cantidad: ");
    scanf("%f",&x89p[i]);
    suma = suma + x89p[i];
  }

  float promedio = suma / 5;
  int cont_mayor_igual=0;
  int cont_menor=0;

  for(int i=0; i<5; i++){
    if(x89p[i] >= promedio){
      cont_mayor_igual++;
    }
    else{
      cont_menor++; 
    }
  }

  printf("cantidad de mayoresIguales al promedio: %d, cantidad de menores al promedio: %d",cont_mayor_igual,cont_menor);
  printf("\n\t\tEl promeido es: %.2f",promedio);

  return 0;
}
