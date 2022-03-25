#include <stdio.h>
#include <string.h>

int main(){

  char origen[]="Programacion";

  char destino[20];

//strcpy(destino,"textoAcopiar");
  strcpy(destino,origen);
  printf("%s<= destino\n",destino);
  printf("%s<- origen\n",origen);

  return 0;
}
