#include <stdio.h>

void llenar_Array(int arrayDes[], int dimension);
int main(void){

  int miVector[5];

  llenar_Array(miVector, 5);

  for(int i=0; i<5; i++){
    printf("  %d",miVector[i]);
  }
  return 0;
}

void llenar_Array(int mango[], int dimension){

  for(int i=0; i<dimension; i++){
    printf("\nIngrese el valor [%d] del array: ", i);
    scanf("%d", &mango[i]); getchar();
  }
}
