#include <stdio.h>

int main(){
  int user_option, peaje;

  printf("1) turismo\n2) autobus\n3) motocicleta");
  printf("\n Ingrese la opci[on:\n");
  scanf("%d",&user_option);

  switch(user_option){
    case 1: peaje=500; printf("El peaje a pagar es $%d\n",peaje); break;
    case 2: peaje=3000; printf("El peaje a pagar es $%d\n",peaje); break;
    case 3: peaje=300; printf("El peaje a pagar es $%d\n",peaje); break;
    default: printf("...ERROR... OPCI[ON INCORRECTA...\n"); break;
  }
  return 0;
}
