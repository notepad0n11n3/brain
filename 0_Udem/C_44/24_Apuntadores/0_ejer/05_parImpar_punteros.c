#include <stdio.h>

int main(void){

  int numero, *apuntador_Numero = &numero ;

  printf("\nIngrese un n[umero: ");
  scanf("%d", &numero); getchar();

  apuntador_Numero = &numero;

  if( *apuntador_Numero % 2 == 0 ){
    printf("\nEl n[umero %d es par", numero );
    printf("\nEl n[umero %d es par", *apuntador_Numero );
    printf("\nLa direcci[on de memoria es; %p", apuntador_Numero );
    printf("\nLa direcci[on de memoria es; %p", &numero );
  }else {
    printf("\nEl n[umero %d es impar", numero );
    printf("\nEl n[umero %d es impar", *apuntador_Numero );
    printf("\nLa direcci[on de memoria es: %p", apuntador_Numero );
    printf("\nLa direcci[on de memoria es: %p", &numero );
  }

  return 0;
}
