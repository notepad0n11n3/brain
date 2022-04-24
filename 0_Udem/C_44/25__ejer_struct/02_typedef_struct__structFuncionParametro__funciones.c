#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Asignatura{
  char Materia[40];
}Asignatura;

typedef struct Alumno{
  Asignatura goro[3];
}Alumno;

void modificar_materias(Alumno *texto_Generico, char name[]);
void mostrar_materias(Alumno *texto_Generico, char nee[]);

int main(void){

  Alumno Manolo,Manuela;   // gracias a typedef Alumno remplaza a 'struct Alumno Manolo;  struct Alumno Manuela;'

  strcpy(Manolo.goro[0].Materia, "Matematicas");
  strcpy(Manolo.goro[1].Materia, "Fisica");
  strcpy(Manolo.goro[2].Materia, "Astronomia");

  strcpy(Manuela.goro[0].Materia, "Natacion");
  strcpy(Manuela.goro[1].Materia, "Boxeo");
  strcpy(Manuela.goro[2].Materia, "Astronomia");



  int a=1;
  while(a==1){
    printf("\n\n\n\tEste programa permite ver las materias, Modificarlas y Crear 1 alumno\n");
    printf("\n1) Ver Materias\n2) Modificar Materias\n3) Alumno Nuevo(solo 1) \n0) Salir...\n");

    Alumno Nuevo;
    char alumnoNuevo[20];

    int user_option;
    scanf("%d",&user_option); getchar();
    switch(user_option){
      case 1:
        printf("\n\t ::: SELECCIONASTE VER MATERIAS...");
        printf("\nDe que alumno quieres ver las Materias?:");
        printf("\n\t1) Manolo\t 2) Manuela\t 3) %s\n\t\t::: ",alumnoNuevo);  // alumnoNuevo no declarado

        int alumno;
        scanf("%d",&alumno); getchar();
        switch(alumno){
          case 1:
            mostrar_materias(&Manolo, "ManOlo");
            break;
          case 2:
            mostrar_materias(&Manuela, "Manuela");
            break;
          case 3:
            mostrar_materias(&Nuevo, alumnoNuevo);
            break;
          default: system("clear"); printf("\n Opci[on incorrecta...!!!\n"); break;
        }
        break;
      case 2:
        printf("\n\t MODIFICAR MATERIAS...\n");
        printf("\n Modificar las materias de: \n");
        printf("\t1) Manolo\t 2) Manuela\t3) %s\t\t0) Back\n",alumnoNuevo);

        int user_modificacion;
        scanf("%d",&user_modificacion); getchar();

        switch(user_modificacion){
          case 1:
            modificar_materias(&Manolo, "Manolo");
            break;
          case 2:
            modificar_materias(&Manuela, "Manuela");
            break;
          case 3:
            modificar_materias(&Nuevo, alumnoNuevo);
            break;
          case 0: break;
          default: system("clear"); printf("\n Opci[on incorrecta...!!!\n") ;break;
        }
        break;
      case 3:
        system("clear");
        printf("\n Nombre nuevo alumno:  ");
        fgets(alumnoNuevo, 20, stdin); strtok(alumnoNuevo, "\n");

        for(int i=0; i<3; i++){
          printf("\nIngrese la materia %d: ",i);
          fgets(Nuevo.goro[i].Materia, 40, stdin); strtok(Nuevo.goro[i].Materia, "\n");
        }
        break;
      case 0: system("clear"); a=2; printf("\n\n\tSaliendo...\n"); break;
      default: system("clear"); printf("\n Opci[on incorrecta...!!!\n"); break;
    }
  }

  return 0;
}

void modificar_materias(Alumno *mango, char name[]){
 printf("\n\t FUNCTION READY FUCK YEAH...#=>> %s\n",name); 
 for(int i=0; i<3; i++){
   printf("\nIngrese la materia %d: ",i+1);
   fgets(mango->goro[i].Materia, 40, stdin); strtok(mango->goro[i].Materia, "\n");
 }
 for(int i=0; i<3; i++){
   printf("\n#=> %s",mango->goro[i].Materia);
 }
 
}

void mostrar_materias(Alumno *mango, char nee[]){
  system("clear");
  printf("\nSeleccionaste a ...FUNCIONES <3%s\n", nee);
  printf("\n\tSus Materias son: \n\t1) %s\n\t2) %s\n\t3) %s\n", mango->goro[0].Materia, mango->goro[1].Materia, mango->goro[2].Materia);
}
