#include <stdio.h>
#include <stdlib.h>

int main(){
  FILE *f;    // stdio.h

  f = fopen("prueba.txt","r");
  char *linea;

  while (feof(f)==0){ // feof(ficheroHere)  devuelve 0 si el fichero todavia tiene contenido, 1 si termino
    
    fscanf(f,"%s",linea);
    printf("%s\n", linea);
  }

  fclose(f);

  return 0;
}
