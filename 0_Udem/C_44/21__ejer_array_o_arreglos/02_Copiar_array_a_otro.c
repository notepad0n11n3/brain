#include <stdio.h>

void copiandoArray(int a[], int b[], int tamano);

int main(){

  int arrayUno[5] = {2,3,4,5,6};
  int arrayDos[5];

  printf("Copiando Array Uno al Dos\n\n");

  copiandoArray(arrayUno, arrayDos, 5);

  return 0;
}

void copiandoArray(int primero[], int segundo[], int tamano){
  for(int i=0; i<tamano; i++){
    segundo[i]=primero[i];
  }
  
  printf("\n Elementos copiados => {");
  for(int i=0; i<tamano; i++){
    printf(" %d ",segundo[i]);
  }
  printf("}\n");
}
