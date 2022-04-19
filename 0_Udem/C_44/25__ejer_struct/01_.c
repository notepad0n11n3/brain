#include <stdio.h>
#include <string.h>

struct Direccion{
  char ciudad[30];
  char calle[40];
};

struct Alumno{
  char nombre[80];
  char apellido[80];
  int edad;
  struct Direccion infoExtraAlumno;
};

int main(void){

  struct Alumno estudiante01;

  strcpy(estudiante01.nombre, "Manolo");
  strcpy(estudiante01.apellido, "neeneeenee");
  estudiante01.edad= 88;
  strcpy(estudiante01.infoExtraAlumno.ciudad, "Japan");
  strcpy(estudiante01.infoExtraAlumno.calle, "Calle Siempre viva 1234");


  printf("\nAlumno 01\n");
  printf("\nNombre: %s %s\n",estudiante01.nombre, estudiante01.apellido);
  printf("\nEdad: %i\n", estudiante01.edad);
  printf("\nDirecci[on: %s - %s\n", estudiante01.infoExtraAlumno.calle, estudiante01.infoExtraAlumno.ciudad);

  return 0;
}
