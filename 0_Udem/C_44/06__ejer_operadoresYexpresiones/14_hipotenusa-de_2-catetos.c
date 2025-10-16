#include <stdio.h>

#include <math.h>


//          ::: gcc 14_hipotenusa-de_2-catetos.c -lm

int main(){
  float cateto1, cateto2, hipotenusa;

  printf("Escribe los valores de los catetos:\n");
  scanf("%f %f",&cateto1,&cateto2);

  hipotenusa = sqrt(pow(cateto1,2)+pow(cateto2,2)); // pow(numero, potencia)

  printf("\nEl valor de la hipotenusa es: %.2f\n",hipotenusa);
  return 0;
}
