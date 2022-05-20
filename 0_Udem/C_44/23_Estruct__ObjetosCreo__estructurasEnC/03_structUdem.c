#include <stdio.h>
#include <string.h>

int main(){
  struct persona{
    char nombre[40];
    int edad;
  }persona1, persona2;

  printf("\nIngrese el nombre: ");
  fgets(persona1.nombre, 40, stdin); strtok(persona1.nombre, "\n");
  printf("\nIngrese la edad: ");
  scanf("%d",&persona1.edad); getchar();

  printf("\nIngrese el nombre: ");
  fgets(persona2.nombre, 40, stdin); strtok(persona2.nombre, "\n");
  printf("\nIngrese la edad: ");
  scanf("%d",&persona2.edad); getchar();


  printf("\nSu nombre es: %s",persona1.nombre);
  printf("\nSu edad es: %d",persona1.edad);

  printf("\nSu nombre es: %s",persona2.nombre);
  printf("\nSu edad es: %d",persona2.edad);
  return 0;
}
