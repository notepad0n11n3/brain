#include <stdio.h>

int main(void){

  char caracter;
  char *apuntador_caracter;

  apuntador_caracter = &caracter;

  for( caracter = 'A'; caracter <= 'Z'; caracter++ ){
    printf(" %c ", *apuntador_caracter);
  }

  printf("\n");

  for( *apuntador_caracter = 'a'; *apuntador_caracter <= 'z'; caracter++){   // no me funciona con *apuntador_caracter++  :(
    printf(" %c ", caracter);
  //printf(" %c ", *apuntador_caracter);
  }

  return 0;
}
