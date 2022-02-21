#include <stdio.h>

// 1 2 3 5 8...
//
// 1+2=3   2+3=5 3+5=8 etc...
int main(){

  int n,i,x=0,y=1,z=1;

  printf("Escribe el n[umero de elementos:\n");
  scanf("%i",&n); getchar();

  printf("----------------------");
  for( i=1; i<n; i++){
    z = x + y;
    x = y;
    y = z;
    printf("%i\n",z);
  }
  return 0;
}
