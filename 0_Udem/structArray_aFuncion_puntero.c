#include <stdio.h>
#include <string.h>

struct Extra{
  char sexo[44];
  int suerte;
};
struct Alumno{
  char nombre[44];
  int edad;
  struct Extra go;
};

void mi_function(struct Alumno *test);
int main(void){
  
  struct Alumno test[2];


  mi_function(&test[0]);

  printf("\n1 => %s , %d", test[0].nombre, test[0].edad);
  printf("\n2 => %s, %d", test[1].nombre, test[1].edad);

  return 0;
}

void mi_function(struct Alumno *test){

  printf("\nmango\n");
  strcpy(test[0].nombre, "primerNobre");
  test[0].edad = 11;

  strcpy(test[1].nombre, "segundoNombre");
  test[1].edad = 22;

  printf("\n1 => %s , %d", test[0].nombre, test[0].edad);
  printf("\n2 => %s, %d", test[1].nombre, test[1].edad);
}
