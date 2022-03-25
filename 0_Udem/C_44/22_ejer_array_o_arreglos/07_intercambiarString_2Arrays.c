#include <stdio.h>
#include <string.h>

#define TAMANIO 30
const int tamano=30;

int main(){
  char dato1[TAMANIO], dato2[tamano], soporte[30];

  printf("\nIngrese el primer string: ");
  fgets(dato1, TAMANIO, stdin); strtok(dato1,"\n");

  printf("\nIngrese el segundo string: ");
  fgets(dato2, tamano, stdin); strtok(dato2, "\n");

  printf("-> dato1  %s\n",dato1);
  printf("-> dato2  %s\n",dato2);

  strcpy(soporte,dato1);
  strcpy(dato1,dato2);
  strcpy(dato2,soporte);

  printf("=> new dato1 %s\n",dato1);
  printf("=> new dato2 %s\n",dato2);
  
  return 0;
}
