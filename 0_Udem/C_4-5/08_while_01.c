#include <stdio.h>
#include <stdlib.h>


// Multiplos de 3  entre 1 y 100

int main(){
  for(int i=1; i<=100; i++){
    if(i%3==0){
      printf("%d\n",i);
    }
  }

  return 0;
}
