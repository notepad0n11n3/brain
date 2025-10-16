#include <stdio.h>
#include <stdlib.h>

int main(){

  FILE *f;
  
  f = fopen("prueba.txt", "a"); // a~adir texto al final del fichero ,"a"
  char *cadena = "Otra cadena de prueba";
  fprintf(f,"%s ",cadena);

  fclose(f);

  return 0;
}
