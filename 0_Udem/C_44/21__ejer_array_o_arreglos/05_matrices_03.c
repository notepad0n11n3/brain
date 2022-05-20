#include <stdio.h>

int main(){
  char matriz[2][3]={'a','b','c','d','e','f'};

  for(int i=0; i<2; i++){
    for(int j=0; j<3; j++){
      printf("%c", matriz[i][j] );
    }
    printf("\n");
  }

  return 0;
}
