#include <stdio.h>

//  Determinar el Factorial de un n[umero
//  1*2*3*4*5*6*7*8*9*10 = 10!            10! == 10factorial
int main(){

  int i,number_user,fact=1;

  printf("Ingresa un n[umero:\n");
  scanf("%i",&number_user); getchar();

  for( i=1; i<= number_user; i++){
    fact *= i;
  }

  printf("El factorial de %i\n",fact);

  return 0;
}
