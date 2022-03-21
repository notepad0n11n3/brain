#include <stdio.h>

#include <string.h>


#define tamanio 15
const int tamano=15;

int main(){
  char nombre1[tamanio], nombre2[tamano];

  printf("Escribe tu nombre\n");
  fgets(nombre1, tamano, stdin); strtok(nombre1,"\n");

  printf("=> %s\n",nombre1);

  strcpy(nombre2, nombre1);

  printf("postCOPY => %s\n",nombre2);
  return 0;
}
