#include <stdio.h>

void black(char *user_data1, char *user_data2);

int main(){
  char user_data1, user_data2;

  black(&user_data1, &user_data2);

  printf("\n\n\t Data1 => %c    Data2 => %c\n", user_data1, user_data2);

  return 0;
}

void black(char *user_data1, char *user_data2){
  printf("\n Ingrese el primer caracter: ");
  scanf("%c", &(*user_data1) ); getchar();

  printf("\n Ingrese el segundo caracter: ");
  scanf("%c", &(*user_data2) ); getchar();
}


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
