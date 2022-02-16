#include <stdio.h>
#include <stdlib.h>
int main(){
  
  system("clear");  // stdlib.h

  int opcion;
  float agregar, retirar, saldo=3000;
  printf("\t******************************************\n");
  printf("\t* Este es un Simulador de Tienda o Cajero*\n");
  printf("\t******************************************\n");
  printf("\n\t\tSelectiona una Opci[on:\n");
  printf("\n1) Depositar Dinero");
  printf("\n2) Retirar Dinero");
  printf("\n3) Salir del Cajero");
  printf("\nOpcion==> ");
  scanf("%i",&opcion);

  switch(opcion){
    case 1:
      printf("Cuanto dinero quiere depositar?:\n");
      scanf("%f",&agregar);
      saldo += agregar;
      printf("Tu saldo actual es de %.2f\n",saldo);
      break;
    case 2:
      printf("Cuanto dinero quiere retirar?:\n");
      scanf("%f",&retirar);
      if(retirar > saldo){
        printf(". . . Saldo insuficiente :(\n");
      }else{
        saldo -= retirar;
        printf("Tu saldo actual es de: %.2f\n",saldo);
      }
      break;
    case 3:
      printf("\n\t\t... SALIENDO DEL PROGRAMA...");
      break;
    default: printf("\n\n ERRO... OPCI[ON INVALIDA"); break;
  }


  
  return 0;
}
