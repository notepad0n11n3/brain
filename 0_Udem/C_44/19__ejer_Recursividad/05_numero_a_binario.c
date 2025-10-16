#include <stdio.h>

void numeroEntero_aBinario(int numero);

int main(){
  int user_number;
  do{
    printf("Ingrese un n]umero: ");
    scanf("%d",&user_number); getchar();
  }while(user_number < 0);

  numeroEntero_aBinario(user_number);
  return 0;
}

void numeroEntero_aBinario(int numero){
  printf("%d\n", numero);  // se genera un buble al usar la funcionRecursiva
  if(numero > 1) numeroEntero_aBinario(numero/2);
  printf("%d", numero%2);
}
