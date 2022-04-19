#include <stdio.h>

void sumar(int ejem1[2][3], int ejem2[2][3]);

int main(){
  int matriz1[2][3]={{1,2,3},{3,2,1}}, matriz2[2][3]={{3,2,1},{1,2,3}};

  sumar(matriz1,matriz2);
  return 0;
}

void sumar(int primero[2][3], int segundo[2][3]){
  for(int i=0; i<2; i++){
    for(int j=0; j<3; j++){
      printf(" %d ", primero[i][j] + segundo[i][j] );
    }
    printf("\n");
  }
}

/*
void sumar(int a[2][2], int b[2][2]){
  int resultado[2][2];

  for(int i=0; i<2; i++){
    for(int j=0; j<2; j++){
      resultado[i][j]= a[i][j] + b[i][j];
    }
  }

  for(int i=0; i<2; i++){
    for(int j=0; j<2; j++){
      printf(" %d ", resultado[i][j] );
    }
    printf("\n");
  }

}
*/
