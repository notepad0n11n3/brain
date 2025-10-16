#include <stdio.h>
#include <string.h>

typedef struct Curso{
  char nombre[40];
}Curso;

typedef struct Alumno{
  Curso nombre_curso[2];
}Alumno;

void imprimir_cursos(Alumno *alumno_impresion);


int main(void){
  Alumno test1;

  strcpy(test1.nombre_curso[0].nombre, "Informatica");
  strcpy(test1.nombre_curso[1].nombre, "Astronomia");

  printf("\nPre_Funcion=> %s - %s\n", test1.nombre_curso[0].nombre, test1.nombre_curso[1].nombre);

  imprimir_cursos(&test1);

  printf("\nPst_Funcion=> %s - %s\n", test1.nombre_curso[0].nombre, test1.nombre_curso[1].nombre);

  return 0;
}

void imprimir_cursos(Alumno *impresion_alumno){
  strcpy(impresion_alumno->nombre_curso[0].nombre, "Fisico_Culturismo");
  strcpy(impresion_alumno->nombre_curso[1].nombre, "M[usica");
  printf("\n#1. %s \n#2. %s\n", impresion_alumno->nombre_curso[0].nombre, impresion_alumno->nombre_curso[1].nombre);
}

// con & y *  podemos modificar el struct original, sin & y * funciona pero los cambios solo permanecen dentro de la funcion, like a variable_Local
