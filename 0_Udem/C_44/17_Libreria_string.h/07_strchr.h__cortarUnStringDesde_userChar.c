#include <stdio.h>
#include <string.h>

int main(){

  char abecedario[]="abcdefghijklmnopqrstuwxyz";
  char corte;

  printf("Ingrese letra donde se cortara el abacedario:\n");
  scanf("%c",&corte); getchar();

  printf("\t=> %s\n", strchr(abecedario, corte) );

  return 0;
}
