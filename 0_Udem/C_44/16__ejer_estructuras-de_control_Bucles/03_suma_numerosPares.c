#include <stdio.h>

int main(){

  int user_number, suma;

  for(int i=0; i<=20; i+=2){
    suma += i;
  }
  printf("El valor final de la suma de pares es: %i\n",suma);

  return 0;
}
