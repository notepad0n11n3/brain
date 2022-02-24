#include <stdio.h>

int goro(int user_number);

int main(){
  int user_number;
  printf("Ingrese un n[umero:\n");
  scanf("%d",&user_number); getchar();

  printf("El factorial de %d es: %d\n",user_number, goro(user_number) );

  return 0;
}

int goro(int des){
  int resultado;
  if(des < 2){return 1;}

  resultado = des * goro(des-1);
  return resultado;
}
