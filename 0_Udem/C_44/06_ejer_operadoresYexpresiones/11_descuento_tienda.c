#include <stdio.h>

// 15% de descuento en una tienda
int main(){
  float precioInicial,descuento,precioFinal;

  printf("Escribe el precio del producto: \n");
  scanf("%f",&precioInicial);

  descuento = precioInicial * 0.15;
  precioFinal = precioInicial - descuento;

  printf("\nPrecio Inicial=> %.2f\n Descuento=> %.2f\n Total a Pagar::: %.2f",precioInicial,descuento,precioFinal);
  
  return 0;
}
