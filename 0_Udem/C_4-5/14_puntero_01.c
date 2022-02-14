#include <stdio.h>
#include <stdlib.h>

int main(){
  float vector[50];

  for(int i=0; i<5; i++){
    printf("Introduce un n[umero: \n");
    scanf("%f",&vector[i]);
  }


  float *puntero_aVector = &vector[0];
  float media = 0;

  for(int i=0; i<5; i++){
    media = media + *(puntero_aVector+i);
  }

  media = media / 5;

  printf("La media de los valores del vector es %.2f", media);

  return 0;
}
