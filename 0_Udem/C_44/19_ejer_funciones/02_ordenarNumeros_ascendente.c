#include <stdio.h>

void orDes();
int main(){
  int num1,num2,num3;
  printf("Ingrese 3 n[umeros:\n");
  scanf("%d %d %d",&num1, &num2, &num3); getchar();

  orDes(num1, num2, num3);
  return 0;
}

void orDes(int a, int b, int c){
  if(a >= b && a >= c){
    if(b >= c){
      printf("%d %d %d\n", a, b, c);
      printf("%d %d %d\n", c, b, a);
    }else{
      printf("%d %d %d\n", a, c, b);
      printf("%d %d %d\n", b, c, a);
    }
  }
  if(b >= a && b>= c){
    if(a >= c){
      printf("%d %d %d\n", b, a, c);
      printf("%d %d %d\n", c, a, b);
    }else{
      printf("%d %d %d\n", b, c, a);
      printf("%d %d %d\n", a, c, b);
    }
  }
  if(c >= a && c >= b){
    if(a >= b){
      printf("%d %d %d\n", c, a, b);
      printf("%d %d %d\n", b, a, c);
    }else {
      printf("%d %d %d\n", c, b, a);
      printf("%d %d %d\n", a, b, c);
    }
  }
}
