#include <stdio.h>

#define TAMANO 5
const int tamanio=5;

void shibo(int data1[], int data2[]);

int main(){
  int data1[TAMANO], data2[tamanio];

  printf("Ingrese los enteros para el array:\n");
  for(int i=0; i<TAMANO; i++){
    printf("\t dato %i: ",i);
    scanf("%d",&data1[i]);
  }

  printf("\n\t Data1={ ");
  for(int i=0; i<5; i++){
    printf("%d ",data1[i]);
  } printf(" }");

  shibo(data1,data2);

  return 0;
}

void shibo(int data1[], int data2[]){
  for(int i=0; i<tamanio; i++){
    data2[i] = data1[i];
  }

  printf("\n\t=> Data2={ ");
  for(int i=0; i<TAMANO; i++){
    printf("%d ", data2[i] );
  }
  printf("}\n");
}
