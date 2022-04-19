#include <stdio.h>
#include <string.h>

int main(){
  char marca[20];
  float precio, descuento, precio_final;

  printf("Ingrese la Marca:\n");
  fgets(marca, 10, stdin);      //  fgets()     stdio.h
  strtok(marca,"\n");           //  strtok()    string.h

  printf("Ingrese el precio:\n");
  scanf("%f",&precio);

  if( strcmp(marca,"honda") == 0 ){
    descuento = precio * 0.05;   // 5% de descuento
    precio_final = precio - descuento;
    printf("El precio final es: %.2f\n",precio_final);
  }else if( strcmp(marca,"zusuki") == 0 ){
    descuento = precio * 0.1;    // 10% de descuento
    precio_final = precio - descuento;
    printf("El precio final es: %.2f\n",precio_final);
  }else if( strcmp(marca,"yamaha") == 0 ){
    descuento = precio * 0.08;   // 8% de descuento
    precio_final = precio - descuento;
    printf("El precio final es: %.2f\n",precio_final);
  }else{
    descuento = precio * 0.02;  // 2% de descuento
    precio_final = precio - descuento;
    printf("El precio final es: %.2f\n",precio_final);
  }

  return 0;
}
