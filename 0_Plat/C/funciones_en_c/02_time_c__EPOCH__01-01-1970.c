#include <stdio.h>
#include <time.h>

time_t mango;

int main(void){

  mango = time(NULL);           // time(NULL)   retorna el tiempo actual del sistema

  printf("El n[umero de horas desde EPOCH 1ro de Enero de 1970 a las 00:00 es: %ld \n", mango/3600); // dividimos / 3600 para pasarlo a horas

  return 0;
}
