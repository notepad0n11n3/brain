#include <stdio.h>

int main(void){

  // long: aplicable a enteros y reales, duplica el rango del tipo  Ej:  long int, long long int, long double.
  short numeroEntero_pequeno;     // 2bytes   [ -32768, 32767 ]

  int entero;

  long int entero_Grande;      // este NO funciona :( , tiene el tama~o igual que el int :'u 

  long long int mega_Entero;   // este si funciona, tiene 8 bytes

  unsigned short edades;      // entero corte sin signo  [ 0 , ]


  unsigned char c;

  unsigned long long int enteroSinSigno;    // entero del 0 - ...

  
  // long: aplicable a enteros y reales, duplica el rango del tipo  Ej:  long int, long long int, long double.

  float real;

  double realDoble;

  long double decimal_Grande;  // decimal de MAYOR precision, mucho mas decimales <3


  return 0;
}
