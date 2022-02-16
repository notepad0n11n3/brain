#include <stdio.h>

int main(){

  //   PREINCREMENTO
  int a = 0;
  int b = ++a; // primeroIncrementa a=1 y despu[es asigna b=a(1)

  printf("=>PREINCREMENTO\nEl valor de a es: %i\nEl valor de b es: %i\n\n\n",a,b);

  //   POSTINCREMENTO
  int c = 0;
  int d = c++; // primero asigna d=c(0) y despu[es incrementa c=1

  printf("=>POSTINCREMENTO\nEl valor de c es: %i\nEl valor de d es: %d\n",c,d);

  return 0;
}
