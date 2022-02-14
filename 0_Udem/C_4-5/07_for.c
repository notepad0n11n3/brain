#include <stdio.h>
#include <stdlib.h>


int main(){

  for(int x=0; x<10; x++){
    printf("%d\n",x);
  }
  printf("\n----------------------\n");

  // de 2 en 2 
  for(int y=0; y<10; y=y+2){
    printf("%d\n",y);
  }


  return 0;
}
