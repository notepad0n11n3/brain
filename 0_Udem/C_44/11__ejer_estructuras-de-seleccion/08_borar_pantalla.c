#include <stdio.h>

#include <stdlib.h>

int main(){
  int numero;

  printf(" Presione 1 para borra la pantalla (::: clear)\n");
  printf("*********************************");

  printf("Ingresa la opci[on: \n");
  scanf("%i",&numero);

  if(numero == 1){
    system("clear");
    printf("\n\t Ha borrado la pantalla\n");
  }else{
    printf("El n[umero ingresado no es 1\n");
  }

  return 0;
}
