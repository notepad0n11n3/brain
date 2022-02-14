#include <stdio.h>
#include <stdlib.h>


int main(){
  int n = 0;
  int x = 8;

  while(n<10){
    printf("%d\n",n);
    n++;
  }

  while(n<10 && x<10){
    printf("no print here U.U");
  }

  return 0;
}
