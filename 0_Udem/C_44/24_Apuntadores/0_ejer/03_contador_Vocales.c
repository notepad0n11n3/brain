#include <stdio.h>
#include <string.h>

int contador_Vocales(char *nombre);

int main(void){
  char nombre[40];

  printf("\nIngrese el nombre [o string: ");
  fgets(nombre, 40, stdin); strtok(nombre, "\n");

  printf("\n => %s , tiene  %d vocales", nombre, contador_Vocales(nombre) );

  return 0;
}

int contador_Vocales(char *nombre){
  int contador=0;

  while(*nombre){
    switch(*nombre){
      case 'a':
      case 'A':
      case 'e':
      case 'E':
      case 'i':
      case 'I':
      case 'o':
      case 'O':
      case 'u':
      case 'U': contador++;
    }
    nombre++;
  }

  return contador;
}
