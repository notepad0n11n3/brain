#include <stdio.h>
#include <string.h>

struct extra{
  char apellido[88];
  int edad2;
};
typedef struct info{
  char nombre[88];
  int edad;
  struct extra mas_info;
}info;

void mi_funcion(info *mango);

int main(void){

  int size_array=2;

//printf("\nIngrese el tama~o del array: ");
//scanf("%d", &size_array); getchar();

  info test1[size_array];

  mi_funcion(test1);

  for(int i=0; i<size_array; i++){
    printf("\n=> %s -- %d -- %s - %d", test1[i].nombre, test1[i].edad, test1[i].mas_info.apellido, test1[i].mas_info.edad2);
  }
  return 0;
}

void mi_funcion(info *mango){

  strcpy(mango[0].nombre, "primerNombre");
  strcpy(mango[0].mas_info.apellido, "mesajeSecreto 1");
  mango[0].edad = 88;
  mango[0].mas_info.edad2 = 882;

  strcpy(mango[1].nombre, "segundoNombre");
  strcpy(mango[1].mas_info.apellido, "mensajeSecreto 2");
  mango[1].edad = 22;
  mango[1].mas_info.edad2 = 222;

}
