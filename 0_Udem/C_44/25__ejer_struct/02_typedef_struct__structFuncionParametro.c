#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Asignatura{
  char Materia[40];
}Asignatura;

typedef struct Alumno{
  Asignatura goro[3];
}Alumno;

int main(void){

  Alumno Manolo,Manuela;   // gracias a typedef Alumno remplaza a 'struct Alumno Manolo;  struct Alumno Manuela;'

  strcpy(Manolo.goro[0].Materia, "Matematicas");
  strcpy(Manolo.goro[1].Materia, "Fisica");
  strcpy(Manolo.goro[2].Materia, "Astronomia");

  strcpy(Manuela.goro[0].Materia, "Matematicas");
  strcpy(Manuela.goro[1].Materia, "Fisica");
  strcpy(Manuela.goro[2].Materia, "Astronomia");



  printf("\nEste programa permite ver las materias, Modificarlas y Cread alumnos\n");
  printf("\n1) Ver Materias\n2) Modificar Materias\n3) Crear Alumnos desde Cero con sus Materias\n0) Salir...\n");

  Alumno Nuevo;
  char alumnoNuevo[20];

  int user_option;
  scanf("%d",&user_option); getchar();
  switch(user_option){
    case 1:
      printf("\n\t SELECCIONASTE VER MATERIAS...");
      printf("\nDe que alumno quieres ver las Materias?:");
      printf("  1) Manolo\t 2) Manuela\t 3) %s",alumnoNuevo);  // alumnoNuevo no declarado

      int alumno;
      scanf("%d",&alumno); getchar();
      switch(alumno){
        case 1:
          printf("\nSeleccionaste a Manolo: ");
          printf("\nSus materias son: \n\t1) %s\n\t2) %s\n\t3) %s\n", Manolo.goro[0].Materia, Manolo.goro[1].Materia, Manolo.goro[2].Materia);
          break;
        case 2:
          printf("\nSeleccionaste a Manuela: ");
          printf("\nSus materias son: \n\t1) %s\n\t2) %s\n\t3) %s\n ",Manuela.goro[0].Materia, Manuela.goro[1].Materia, Manuela.goro[2].Materia);
          break;
        case 3:
          break;
        default: system("clear"); printf("\n Opci[on incorrecta...!!!\n"); break;
      }
      break;
    case 2:
      printf("\n\t MODIFICAR MATERIAS...\n");
      printf("\n Modificar las materias de: \n");
      printf("\t1) Manolo\t 2) Manuela\n");

      int user_modificacion;
      scanf("%d",&user_modificacion); getchar();

      switch(user_modificacion){
        case 1:

          break;
        case 2:
          break;
        default: system("clear"); printf("\n Opci[on incorrecta...!!!\n") ;break;
      }
      break;
    case 3:
      break;
    default: system("clear"); printf("\n Opci[on incorrecta...!!!\n"); break;
  }

  return 0;
}
