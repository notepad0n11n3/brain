#include <stdio.h>

int user_data(int *filas, int *columnas);

int main(){
  int filas, columnas;
  user_data(&filas, &columnas);

  printf("\n=> %d , => %d\n",filas,columnas);



  return 0;
}

int user_data(int *filas, int *columnas){
  printf("Ingrese el n[umero de filas: ");
  scanf("%d",&(*filas) ); getchar();
  
  printf("\nIngrese el n[umero de columnas: ");
  scanf("%i",&(*columnas) ); getchar();

}
