#include <stdio.h>

int main(){
  int a,b,d;
  float c;
  a=b=c=d= 10;
//a = a + 3;
  a += 3;
  b *= 3;
  d -= 3;
  c /= 3;

  printf("a => %i :: ",a);
  printf("b => %i :: ",b);
  printf("c => %.2f :: ",c);
  printf("d => %i :: ",d);

  return 0;
}
