/*
 *  Palabras Reservadas y conversion de tipos de datos (casting)
 *
 *    existen 32 palabras reservadas: if, else, return, while, char, int, double, break, continue, long, case, short, for,  etc...
 */

#include <stdio.h>

int main()
{
  int a = 80;  // para char 80 es la letra p   

  printf(" entero %i\n flotante %.2f\n double %.3f\n caracter %c\n",a, (float)a, (double)a, (char)a);

  int b = 80;
  float f = 45.3;
  float suma = (float)b + f;
  printf("%.2f",suma);

  return 0; // termina el programa
}
