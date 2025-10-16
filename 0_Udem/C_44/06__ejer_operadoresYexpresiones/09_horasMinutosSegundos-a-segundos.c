#include <stdio.h>

int main(){
  int horas,minutos,segundos;

  printf("Ingresa el n]umero de horas: \n");
  scanf("%d",&horas);

  printf("Ingresa el n[umero de minutos: \n");
  scanf("%d",&minutos);

  printf("Ingresa el n[umero de segundos: \n");
  scanf("%i",&segundos);

  // convertir horas a minutos, minutos a segundos y sumar los segundos 

  int tiempoHoras,tiempoMinutos,tiempoSegundos,total;

  tiempoHoras = horas * 3600;
  tiempoMinutos = minutos * 60;
  tiempoSegundos = segundos;

  total = tiempoHoras + tiempoMinutos + tiempoSegundos;

  printf("El equivalente en segundos es: %d",total);

  return 0;
}
