#include <stdio.h>

#define FILAS 100
#define COLUMNAS 100


void muestra(int A[][COLUMNAS], int N, int M);


int main(){
  int N, M, A[FILAS][COLUMNAS];

  fprintf(stdout, "\n\tIngrese cantidad de filas: "); scanf("%d", &N);
  fprintf(stdout, "\n\tIngrese cantidad de columnas: "); scanf("%d", &M);

  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      fprintf(stdout, "\n\t\t Ingrese el valor de la celda \"[%d][%d]\": ", i, j);
      scanf("%d", &A[i][j]);
    }
  }printf("\n");

  muestra(A, N, M); // solo A es como pasar la direcci[on de memoria  A[0][0] ===  A   (valorX_referencia)

  return 0;
}

void muestra(int A[][COLUMNAS], int N, int M){
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      printf("%d", A[i][j]);
    }
    printf("\n");
  }
}
