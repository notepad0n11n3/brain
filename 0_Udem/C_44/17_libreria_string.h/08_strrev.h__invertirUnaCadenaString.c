#include <stdio.h>
#include <string.h>

void invertirCadenaDes(char cadena[]){
  int longitud = strlen(cadena);

  for(int i=0; i < strlen(cadena) / 2; i++){
    char temporal = cadena[i];
    cadena[i] = cadena[longitud - i - 1];
    cadena[longitud - i - 1] = temporal;
  }
}

int main(){

  char cadena[]="Hola";

  invertirCadenaDes(cadena);

  printf("Cadena invertida: %s\n",cadena);

  return 0;
}

