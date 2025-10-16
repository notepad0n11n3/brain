#include <stdio.h>

int main(){
  float base_Mayor, base_Menor, altura, area;

  printf("Ingrese la base mayor: \n");
  scanf("%f",&base_Mayor);

  printf("Ingrese la base manor: \n");
  scanf("%f",&base_Menor);

  printf("Ingrese la altura: \n");
  scanf("%f",&altura);

  area = ((base_Mayor + base_Menor) * altura)/2;

  printf("El area es: %.2f",area);
  return 0;
}
