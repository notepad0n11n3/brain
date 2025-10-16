#include <stdio.h>

int main(int argc, char *argv[]){

  char cadena1[30] = "Hola";  // el \0 se pone automaticamente al final del string

  char cadena2[30] = {'H', 'o', 'l', 'a', '\0'};

  char *cadena3 = "Hola2";

  return 0;
}
