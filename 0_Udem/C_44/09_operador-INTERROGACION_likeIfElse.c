#include <stdio.h>

// Expresi[on condicional Operador '?'
//
//  Sintaxis:
//              Condicion ? Expresion1: Expresion2 
int main(){
  
  int numero;
  printf("Escribe un n[umero:\n");
  scanf("%i",&numero);

  (numero%2==0) ? printf("El n[umero es par\n") : printf("Es impar\n");

  return 0;
}
