#include <stdio.h>

                    
                      // numero primo == n[umero divisible entre 1 y entre si mismo
int main(void){

  int numero, *apuntador_Numero = &numero, contador = 0;

  printf("\nIngrese un n[umero: ");
  scanf("%d", &numero); getchar();

  for(int i=1 ; i<=*apuntador_Numero; i++){
    if(*apuntador_Numero % i == 0){
      contador++;
    }
  }

  if(contador > 2){
    printf("\nEl n[umero %d no es primo", *apuntador_Numero);
    printf("\nPosici[on en memoria: %p", apuntador_Numero);
  }else {
    printf("\nEl n[umero %d es primo", *apuntador_Numero);
    printf("\nPosici[on en memoria: %p", apuntador_Numero);
  }

  return 0;
}
