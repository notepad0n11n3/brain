#include <stdio.h>

int main(){
  int numero;

  printf("Ingrese el n[umero: \n");
  scanf("%d",&numero);

  if(numero%2 == 0){
    printf("El n[umero %d es par\n",numero);
  }else{
    printf("El n[umero %d es impar\n",numero);
  }

  return 0;
}
