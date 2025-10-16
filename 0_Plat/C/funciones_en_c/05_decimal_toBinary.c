#include <stdio.h>
#include <stdlib.h>

int main(void){

  int binaryNumber[12], user_data, i;

  printf("\nIngrese un valor decimal\n");
  scanf("%d", &user_data);
  printf("\n\tUsted va a convertir el n[umero %d a binario\n", user_data);

  for( i=0; user_data>0; i++){
    printf("\n=> i = %d\n", i);
    binaryNumber[i] = user_data%2;
    user_data = user_data/2;
  }

  printf("\nEl resultado de la conversion es: ");
  for( i=i-1; i>=0; i--){  // por alguna razon i regresa con valor 5, tenemos que restar 1 :u
    printf("\n=> i = %d\n", i);
    printf("%d", binaryNumber[i]);
  }

  return 0;
}
