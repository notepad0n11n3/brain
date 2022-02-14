#include <stdio.h>
#include <stdlib.h>

int main(){
  
  FILE *f;

  f = fopen("prueba.txt","w");// ,"w" sobreEscribirFichero ,"r" read   ,"a" a~adir al finalDelFichero

  char *cadena = "cadena de prueba";

  fprintf(f,"%s\n",cadena);

  fclose(f);

  return 0;
}
