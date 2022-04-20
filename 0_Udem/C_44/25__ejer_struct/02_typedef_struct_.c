#include <stdio.h>
#include <string.h>


typedef struct Asignatura{
  char Materia[40];
}Asignatura;

typedef struct Alumno{
  Asignatura goro[5];
}Alumno;

int main(void){

  Alumno Manolo,Manuela;   // gracias a typedef Alumno remplaza a 'struct Alumno Manolo;  struct Alumno Manuela;'

  strcpy(Manolo.goro[0].Materia, "Matematicas");
  strcpy(Manolo.goro[1].Materia, "Fisica");
  strcpy(Manolo.goro[2].Materia, "Astronomia");
  strcpy(Manolo.goro[3].Materia, "Historia");
  strcpy(Manolo.goro[4].Materia, "Cocina");

  strcpy(Manuela.goro[0].Materia, "Matematicas");
  strcpy(Manuela.goro[1].Materia, "Fisica");
  strcpy(Manuela.goro[2].Materia, "Astronomia");
  strcpy(Manuela.goro[3].Materia, "Mecanografia");
  strcpy(Manuela.goro[4].Materia, "FIsico_Culturismo");
  return 0;
}
