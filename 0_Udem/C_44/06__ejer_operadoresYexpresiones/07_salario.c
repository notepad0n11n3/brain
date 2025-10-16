#include <stdio.h>

int main(){
  int horas, salario_hora, salario_total;

  printf("Introduce las horas trabajadas: \n");
  scanf("%i",&horas);

  printf("Introduce el salario por hora: \n");
  scanf("%i",&salario_hora);

  salario_total = horas * salario_hora;

  printf("El salario total es: %i",salario_total);
  return 0;
}
