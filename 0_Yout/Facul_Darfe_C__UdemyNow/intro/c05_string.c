#include <stdio.h>
#include <string.h>

#define TMAX 40

typedef char tCadena[TMAX];

int main(int argc, char *argv[]){

  tCadena s1 = "Hola", s2 = " mundo";

  fprintf(stdout, "\n\t::s1:: %d\n", strlen(s1) );
  fprintf(stdout, "%s\n", s1);
  fprintf(stdout, "%s\n", s2);

  strcat(s1, s2); // pega el contenido de s2 en s1 <3...
  fprintf(stdout, "\n\t::s1:: %d\n", strlen(s1) );
  fprintf(stdout, "%s\n", s1);
  fprintf(stdout, "%s\n", s2);

  strcpy(s2, s1);
  fprintf(stdout, "\tpost strcpy::  %s\n", s2);
  return 0;
}
