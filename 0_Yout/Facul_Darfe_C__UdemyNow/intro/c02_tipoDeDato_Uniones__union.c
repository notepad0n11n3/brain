#include <stdio.h>

// union ocupa el mismo lugar de la memoria para todas sus variables internas.

typedef struct{
  char *nombre;
  int edad;
  union{
    long fijo, cel, fax;    // si modificas 1 modificas todos, usan el mismo espacio en memoria... eso creo.
  }telefono;
}tPersona;

int main(int argc, char *argv[]){

  tPersona p1;

  p1.nombre = "Ricardo";
  p1.edad = 51;

// union ocupa el mismo lugar de la memoria para todas sus variables internas.
  p1.telefono.fijo = 123456;
  p1.telefono.cel = 987064;
// union ocupa el mismo lugar de la memoria para todas sus variables internas.
  
  // accedemos a union como a un struct normal, con '.'
  fprintf(stdout, "\n\t Nombre: %s, Edad: %d, Telefono: %ld \n", p1.nombre, p1.edad, p1.telefono.fijo);
// union ocupa el mismo lugar de la memoria para todas sus variables internas.

  return 0;
}
