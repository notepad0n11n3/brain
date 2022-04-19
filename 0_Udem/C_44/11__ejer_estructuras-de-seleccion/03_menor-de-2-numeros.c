#include <stdio.h>

int main(){
  int num1,num2;

  printf("Ingresa 2 enteros:\n");
  scanf("%d %d",&num1,&num2);

  if(num1<num2){
    printf("El primer n[umero %d es menor que %d\n",num1,num2);
  }
  if(num1>num2){
    printf("El segundo n[umero %d es menor que %d\n",num2,num1);
  }
  return 0;
}
