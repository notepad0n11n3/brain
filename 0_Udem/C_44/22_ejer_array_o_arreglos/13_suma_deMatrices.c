#include <stdio.h>

int filasColumnas_user(int *filas, int *columnas);

int main(){
  int filas, columnas;

  filasColumnas_user(&filas, &columnas);

  int matri[filas][columnas];
  printf("\nFilas=> %d ,Columnas=> %d\n",filas,columnas);

  for(int i=0; i<filas; i++){
    for(int j=0; j<columnas; j++){
      printf("\nDato posici[on [%d][%d]: ",i,j);
      scanf("%d", &matri[i][j] );
    }
  }

  printf("\n neeee.....\n");
  for(int i=0; i<filas; i++){
    for(int j=0; j<columnas; j++){
      printf("%d ",matri[i][j] );
    }
  }
  return 0;
}


int filasColumnas_user(int *filas, int *columnas){
  printf("Ingrese el n[umero de filas: ");
  scanf("%d",&(*filas) ); getchar();
  
  printf("\nIngrese el n[umero de columnas: ");
  scanf("%i",&(*columnas) ); getchar();
}
