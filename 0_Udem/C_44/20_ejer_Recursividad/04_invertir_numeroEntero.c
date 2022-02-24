#include <stdio.h>

void invertir(int numero);
int main(){
  int user_number;
  do{
    printf("Ingrese un entero:\n");
    scanf("%d",&user_number); getchar();
  }while(user_number < 0);

  invertir(user_number);

  return 0;
}

void invertir(int numero){
  printf("%i",numero%10);
  if(numero > 10) invertir(numero/10);
}
