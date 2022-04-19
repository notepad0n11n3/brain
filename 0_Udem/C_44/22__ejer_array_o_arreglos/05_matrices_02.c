#include <stdio.h>

int main(){
  float x89p[2][3];

  for(int i=0; i<2; i++){
    for(int e=0; e<3; e++){
      printf("\nIngrese el valor matriz[%i][%d]: ",i,e);
      scanf("%f",&x89p[i][e] ); getchar();
    }
    printf("\n");
  }

  for(int i=0; i<2; i++){
    for(int e=0; e<3; e++){
      printf(" %.2f ",x89p[i][e] );
    }
    printf("\n");
  }
  return 0;
}
