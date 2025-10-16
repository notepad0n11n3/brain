#include <stdio.h>

int main(){
  float lado,area;
  printf("\t Este programa calcula el area de un cuadrado\n Inserta el valor del lado: ");
  scanf("%f",&lado);

  area = lado * lado;
  printf("El area del cuadrado es: %.2f",area);

  return 0;
}
