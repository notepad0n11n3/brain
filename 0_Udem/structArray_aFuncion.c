#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
  char apellido[40];
}info_extra;

typedef struct{
  char nombre[40];
  info_extra gorone;
}alumno;

void mi_funcion(alumno test1[]);

int main(void){
  printf("\nHello men...\n");

  alumno mango[2];
  mi_funcion(mango);

  printf("\n\t => %s ,  => %s\n", mango[0].nombre, mango[0].gorone.apellido);
  printf("\n\t => %s ,  => %s\n", mango[1].nombre, mango[1].gorone.apellido);

  return 0;
}

void mi_funcion(alumno test1[]){
  strcpy(test1[0].nombre, "2b");
  strcpy(test1[0].gorone.apellido, "assasin");

  strcpy(test1[1].nombre, "9s");
  strcpy(test1[1].gorone.apellido, "hacker");

  printf("\n\t => %s ,  => %s\n", test1[0].nombre, test1[0].gorone.apellido);
  printf("\n\t => %s ,  => %s\n", test1[1].nombre, test1[1].gorone.apellido);

  strcpy(test1[0].nombre, "2bnew");
  strcpy(test1[0].gorone.apellido, "new-assasin");

  strcpy(test1[1].nombre, "9snew");
  strcpy(test1[1].gorone.apellido, "new-hacker");
}
