#include <stdio.h>

int main(void){

  int array[5] = {1,2,3,4,5};

  int *apuntador_Array = &array[0];  // puntero al inicio del array


  while( *apuntador_Array != NULL ){      //  NO ES CONFIABLE, SALTAN 3 DATOS EXTRA AL FINAL...  INVESTIGA
    printf("\n %d", *apuntador_Array);
    apuntador_Array++;       //  recorremos el array agregando ++,  <3 <3 <3... ... .
  }

  return 0;
}
