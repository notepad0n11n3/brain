#include <stdio.h>
#include <string.h>

  // strlen(cadenaString);
  //  Devuelve un entero que representa la longitud de una cadenaString incluyendo espaciosEnBlanco
  //  pero excluyendo el caracter nulo  '\0'
int main(){

  char user_data[200];

  printf("Ingresa un string: \n");
  fgets(user_data, 200, stdin); strtok(user_data, "\n");

  printf("La longitud de la cadena digitada es: %d\n", strlen(user_data) );

  return 0;
}
