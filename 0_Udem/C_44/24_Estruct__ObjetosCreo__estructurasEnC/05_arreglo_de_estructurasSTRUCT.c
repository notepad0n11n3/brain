#include <stdio.h>
#include <string.h>

struct persona{
  char nombre[20];
  int edad;
}personas[5];    //  ==== }persona0, persona1, persona2, persona3, persona4;

int main(){

  for(int i=0; i<5; i++){
    printf("\n%i. Escribe su Nombre: ", i);
    fgets(personas[i].nombre, 20, stdin); strtok(personas[i].nombre, "\n");

    printf("\n %i. Ingrese la edad: ", i);
    scanf("%d",&personas[i].edad); getchar();
  }

  for(int i=0; i<5; i++){
    printf("\nEl nombre es: %s  y la edad es: %d",personas[i].nombre, personas[i].edad);
  }

  return 0;
}
