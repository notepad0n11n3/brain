#include <stdio.h>

/* calcular tarifas de saldo de celulares
 *    de 1000 a 1500 Premium
 *    de 500 a 999   Intermedia
 *    de 100 a 499   B[asica
 */

#define Tarifa3 "Premium"
#define Tarifa2 "Intermedia"
#define Tarifa1 "Basica"

int main(){
  float precio;

  printf("Ingrese el monto dispuesto a pagar por el plan: \n");
  scanf("%f",&precio);

  if(precio <= 500 && precio >= 100){
    printf("La tarifa sugerida es: %s", Tarifa1);
  }
  if(precio >= 500 && precio < 1000){
    printf("La tarifa sugerida es: %s", Tarifa2);
  }
  if(precio <=1500 && precio >= 1000){
    printf("La tarifa sugerida es: %s", Tarifa3);
  }
  return 0;
}
