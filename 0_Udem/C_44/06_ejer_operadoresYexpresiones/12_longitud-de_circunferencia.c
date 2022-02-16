#include <stdio.h>

#define PI 3.1416
int main(){
  float radio, longitud;

  printf("Escribe el valor del radio de la circunferencia: \n");
  scanf("%f",&radio);

  longitud = 2*PI*radio;

  printf("La longitud de la circunferencia es: %.2f\n", longitud);

  return 0;
}
