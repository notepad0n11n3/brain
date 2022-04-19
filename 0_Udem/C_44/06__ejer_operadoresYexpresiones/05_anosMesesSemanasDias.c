#include <stdio.h>

int main(){

  int userYears,meses,semanas,dias,horas;
  printf("Ingrese los a~os:\n");
  scanf("%i",&userYears);

  meses = userYears * 12;
  semanas = meses * 4;
  dias = semanas * 7;
  horas = dias * 24;

  printf("meses=>%i\nsemanas=>%i\ndias=>%i\nhoras=>%i\n",meses,semanas,dias,horas);

  return 0;
}
