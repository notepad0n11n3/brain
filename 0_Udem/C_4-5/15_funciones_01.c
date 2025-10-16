#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void multiplicaVector(int *vector, int  nElementos, int numero);

int main(){

  int vector[10]={1,2,3,4,5,6,7,8,9,10};

  multiplicaVector(&vector[0], 10, 3);

  for(int i=0; i<10; i++){
    printf("%d", vector[i]);  // Guardamos el resultado dentro del mismo array/vector en la func multiplicaVec...
  }
}

void multiplicaVector(int *vector, int nElementos, int numero){
  for(int i=0; i<nElementos; i++){
    *(vector+i) = *(vector+i) * numero;
  }

  return 0;
}
