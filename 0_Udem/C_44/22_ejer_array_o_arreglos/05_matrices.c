#include <stdio.h>

int main(){
  int matriz[2][3]={1,2,3,11,12,13};
  int filas, columnas;

  for(filas=0; filas<2; filas++){
    for(columnas=0; columnas<3; columnas++){
      printf("%i ", matriz[filas][columnas] );
    }
    printf("\n");
  }
  return 0;
}
