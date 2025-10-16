#include <stdio.h>

int main(){

  int user_start, user_end, sumaPares;

  printf("Ingresa el n[umero de inicio:\n");
  scanf("%d",&user_start); getchar();

  printf("Ingresa el n[umero final:\n");
  scanf("%d",&user_end); getchar();

  int i=user_start;
  while(i <= user_end){
    if(i%2 == 0){
      sumaPares += i;
    }
    i++;
  }

  printf("La suma de todos los pares de %d a %d es: %d\n",user_start,user_end,sumaPares);

  return 0;
}
