#include <stdio.h>
#include <stdlib.h>


int main(){

  int m[3][2] = {{0,1},{2,3},{4,5}};

  printf("%d\n",m[1][1]);

  m[2][0]=40;

  for(int i=0; i<3; i++){
    for(int j=0; j<2; j++){
      printf("%d",m[i][j]);
    }
    printf("\n");
  }

  return 0;
}
