#include <stdio.h>
#include <stdlib.h>

int main(){

  float vector[5];

  for(int i=0; i<5; i++){
    printf("Introduce un n[umero real: \n");
    scanf("%f",&vector[i]);
  }

  float *punteroDes = &vector[0];
  float media=0;

  for(int i=0; i<5){
    media = media + *(punteroDes + i)
  }

  media = media / 5;

  printf("La media de los valores del vector es %.2f \n", media);

}
