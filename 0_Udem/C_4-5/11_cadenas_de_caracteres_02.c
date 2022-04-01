#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Pide una cadena y un caracter, print el lugar de la primera aparici[on del caracter en la cadena
int main(){
  char cadena[50];
  char caracter;

  printf("Introduce una cadena:\n");
  fgets(cadena, 50, stdin); strtok(cadena, "\n");

  printf("Ingroduce un caracter:\n");
  caracter = getchar();     // <- si... extra~o pero funciona <3

  int i=0;
  int pos=-1;
  while(cadena[i] != '\0' && pos == -1){
    if(cadena[i] == caracter){
      pos = i + 1;
    }
    i=i+1;
  }
  if(pos != -1){
    printf("El caracter %c se encuentra en la cadena %s en la posicion %d",caracter, cadena, pos);
  }
  else{
    printf("El caracter %c no se encuentra en la cadena %s",caracter, cadena);
  }

  return 0;
}
