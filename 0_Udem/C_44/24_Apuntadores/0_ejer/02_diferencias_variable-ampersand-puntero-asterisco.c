#include <stdio.h>

int main(void){

  char caracter, *apuntador_caracter;   // dar[a error hasta que le asignes la una direcci[on de memoria(&) al apuntador declarado(*)   // Estamos Inicializando un apuntador con el * like a   char *apuntaodr_caracter;
  apuntador_caracter = &caracter;

  printf(" Caracter:  %d  -  %c  -  %p  \n", caracter, caracter, caracter);                                          // valor VALOR
  printf(" Caracter:  %d  -  %c  -  %p  \n", &caracter, &caracter, &caracter);                                       // direcci[onMemoria
  printf(" Caracter:  %d  -  %c  -  %p  \n", apuntador_caracter, apuntador_caracter, apuntador_caracter);            // direcci[onMemoria
  printf(" Caracter:  %d  -  %c  -  %p  \n", *apuntador_caracter, *apuntador_caracter, *apuntador_caracter);         // valor VALOR

  return 0;
}
