#include <stdio.h>

int main(){
  float precio, descuento, compraDescuento;

  printf("Dale el precio del producto: \n");
  scanf("%f",&precio);

  descuento = precio * 0.15;   // 15% de descuento
  compraDescuento = precio-descuento;

  printf("El precio del producto con el descuento es de: %f\nEl total descontado es: %f\n",compraDescuento,descuento);


  return 0;
}
