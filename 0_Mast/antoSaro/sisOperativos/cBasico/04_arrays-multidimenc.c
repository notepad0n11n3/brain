#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//puntero PUNTERO
//    tipo *nombrePuntero = memoryAllocation(tama~oTipo * cantidad)

int main() {
//char c[2][8] = {"Hola", "Mensaje"};
//char c[][8] = {"Hola", "Mensaje"}; //se puede omitir el 2, pero na cantidad max de bites (8) no se puede omitir

//printf("%s\n",c[0]);
//printf("%s\n",c[1]);
  
  char **stringsGoro = malloc(sizeof(char*) * 2); // ** puntero a punteros
                                         //sizeof(char*)  cuanto ocupaUnPuntero a char
  char *msg1 = malloc(sizeof(char) * 8);
  char *msg2 = malloc(sizeof(char) * 8); //sizeof(char)  cuanto ocupa un char

  strcpy(msg1, "Hola");   // <string.h>
  strcpy(msg2, "Mensaje");// <string.h>

  stringsGoro[0] = msg1;
  stringsGoro[1] = msg2;

  printf("%s\n", stringsGoro[0]);
  printf("%s\n", stringsGoro[1]);
}
