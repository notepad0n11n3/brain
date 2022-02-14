#include <stdio.h>
#include <stdlib.h>

int main(){

  int vector[10]={0,1,2,3,4,5,6,7,8,9};

  vector[9]=99;
  vector[8]=88;

  for(int i=0; i<10; i++){
    printf("%d\n",vector[i]);
  }

  return 0;
}
