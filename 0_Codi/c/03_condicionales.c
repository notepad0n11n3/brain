/*
  Toma de Decisiones if
  operadores de Igualdad               |  Operadores de Relaci[on 
    ==  x es igual que y               |    x > y   x es mayor que y
    !=  x es diferente que y           |    x < y   x es meno que y
                                       |     >=     x es mayor o igual que y
                                       |     <=     x es menor o igual que y
*/


#include <stdio.h>

int main()
{
  int edad;
  printf("Ingrese su edad:...");
  scanf("%d",&edad);      //*    %d Espera un int(entero), &edad  & introduce el dato en la variable edad
  if ( edad >= 18 )
  {
    printf("Eres mayor de edad");
  }
  else if ( edad == 17 )
  {
    printf("sorry bro, casi eres mayor de edad... :( ");
  }
  else{
    printf("Eres menor de edad");
  }
  return 0; //* Termina el programa............!!!!!!!!!!!!!!!!!
}
