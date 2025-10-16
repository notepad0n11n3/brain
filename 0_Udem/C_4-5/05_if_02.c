#include <stdio.h>
#include <stdlib.h>


int main(){
  int precio_base, kilometros;
  float consumo, precio_final;

  printf("\nIntroduce el precio base del vehiculo: ");
  scanf("%d",&precio_base);

  printf("\nIntroduce los kilometros: ");
  scanf("%d",&kilometros);

  printf("\nIntroduce el consumo: ");
  scanf("%f",&consumo);

  if( kilometros < 2000 && consumo <= 5){
    precio_final = precio_base * 1.2;
  }
  else if( kilometros > 2000 && consumo <= 5){
    precio_final = precio_base * 1.1;
  }
  else if(consumo > 5){
    precio_final = precio_base * 1.05;
  }

  printf("El precio final del vehiculo es :  %.2f",precio_final);

  return 0;
}
