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
  float promedio;
  struct Direccion infoExtraAlumno;
};

int main(void){

  struct Alumno estudiante01;

  strcpy(estudiante01.nombre, "Manolo");
  strcpy(estudiante01.apellido, "neeneeenee");
  estudiante01.edad= 88;
  estudiante01.promedio=11.1;
  strcpy(estudiante01.infoExtraAlumno.ciudad, "Tokio");
  strcpy(estudiante01.infoExtraAlumno.calle, "Calle Siempre viva 1234");


  printf("\nAlumno 01\n");
  printf("\nNombre: %s %s\n",estudiante01.nombre, estudiante01.apellido);
  printf("\nEdad: %i\n", estudiante01.edad);
  printf("\nPromedio: %.2f\n", estudiante01.promedio);
  printf("\nDirecci[on: %s - %s\n", estudiante01.infoExtraAlumno.calle, estudiante01.infoExtraAlumno.ciudad);

  struct Alumno *apAlumno;
  apAlumno = &estudiante01;

  strcpy(apAlumno->nombre, "Mango_apuntador");
  strcpy(apAlumno->apellido, "unununu_apuntador");
  apAlumno->edad=111;
  apAlumno->promedio=99.99;
  strcpy(apAlumno->infoExtraAlumno.ciudad, "newCity_apuntador");
  strcpy(apAlumno->infoExtraAlumno.calle, "newStreet_apuntador");

  printf("\n\n\t\t #=> new_city \n");

  printf("\nAlumno 01\n");
  printf("\nNombre: %s %s\n",estudiante01.nombre, estudiante01.apellido);
  printf("\nEdad: %i\n", estudiante01.edad);
  printf("\nPromedio: %.2f\n", estudiante01.promedio);
  printf("\nDirecci[on: %s - %s\n", estudiante01.infoExtraAlumno.calle, estudiante01.infoExtraAlumno.ciudad);

  return 0;
}
