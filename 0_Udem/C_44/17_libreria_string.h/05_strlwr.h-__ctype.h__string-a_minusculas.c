#include <stdio.h>
#include <string.h>

#include <ctype.h>

int main(){

  char texto[100];

  printf("Ingresa una cadena con may[usculas y min[usculas:\n");
  fgets(texto,100,stdin); strtok(texto,"\n");


  for(int indice=0; texto[indice] != '\0'; indice++){
    texto[indice] = tolower(texto[indice]);   // tolower(string[i]);     ctype.h
  }

  printf("El nuevo texto es el siguiente:\n");
  printf("%s\n",texto);

  return 0;
}
