#include <stdio.h>

int main(){
                  // 16 espacios para 1i6 caracteres, todo final de linea lleva un extra '\0' 
  char cadena[16]="estaEs unaCadena";   // le doy una posici[on extra para el '\0', si le doy espacioExacto le imprime una 'G' al final de linea :(
  char arrayDes[16]={'e','s','t','o',' ','E','s',' ','u','n','a',' ','a','r','r','y'};// le doy una posici[on extra para el '\0', si le doy espacioExacto le imprime una 'G' al final de linea :(

  printf("cadenaString=> %s\n",cadena);
  printf("\n----------------------\n");
  printf("arrayArreglo=> %s\n",arrayDes);
  printf("\n----------------------\n");

  for(int i=0; i<16; i++){
    printf("%c",arrayDes[i]);
  }

  printf("\n----------------------\n");
  for(int i=0; i<16; i++){
    printf("array[%d] => %c\n",i,arrayDes[i]);
  }

  printf("\n----------------------\n");
  for(int i=0; i<16; i++){
    printf("cadena[%d] ==> %c\n",i,cadena[i]);
  }
  return 0;
}
