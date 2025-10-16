#include <stdio.h>

int main(){
  float salario,porcentaje,nuevoSalario;

  printf("Ingrese el salario: \n");
  scanf("%f",&salario);

  porcentaje = salario * 0.25;
  nuevoSalario = salario + porcentaje;
  printf("Tiene un aumento de: %.2f\n El nuevo salario es de: %.2f",porcentaje,nuevoSalario);
  return 0;
}
