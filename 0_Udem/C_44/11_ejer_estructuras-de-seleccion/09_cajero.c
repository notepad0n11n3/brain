#include <stdio.h>

int main(){
  float saldo_Inicial=1000, cantidad;
  int option_user;

  printf("\t-- CAJERO AUTOMATICO --");
  printf("\n\n1) Agregar dinero a la cuenta\n");
  printf("2) Retirar dinero de la cuenta\n");
  printf("3) Ver saldo actual\n");
  printf("4) Salir...\n");
  scanf("%d",&option_user);

  switch(option_user){
    case 1: 
      printf("Seleccion[o agregar dinero a la cuenta\n");
      printf("\tIngrese la cantidad que desea agregar:\n");
      scanf("%f",&cantidad);
      saldo_Inicial += cantidad;
      printf("El saldo actual es: %.2f",saldo_Inicial);
      break;
    case 2:
      printf("Seleccion[o retirar dinero\n");
      printf("\tIngrese la cantidad que desea retirar");
      scanf("%f",&cantidad);
      saldo_Inicial -= cantidad;
      printf("El saldo actual es: %.2f",saldo_Inicial);
      break;
    case 3:
      printf("\n\t El saldo actual es de: %.2f",&saldo_Inicial);
      break;
    case 4:
      printf("\n\n\t\t.....SALIENDO DEL PROGRAMA...");
      break;
    default:
      printf("\n\t ERROR... OPCI[ON INV[ALIDA :(");
      break;
  }
  
  return 0;
}
