#include <stdio.h>
#include <stdlib.h>


int main() {
  float euros;
  printf("Introduce los euros que quieres convertir: ");
  scanf("%f",&euros);

  //soles a euros 
  printf("%.2f Euros equivalen a %.2f soles",euros,euros*4.33);

  return 0;
}
