#include <stdio.h>

int main(){

  int user_number;

  printf("Ingrese el n[umero de filas:\n");
  scanf("%d",&user_number); getchar();

  for(int i=0; i < user_number; i++){
    for(int x=0; x <= i; x++){
      printf("*");
    }
    printf("\n");
  }
  return 0;
}
