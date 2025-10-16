#include <stdio.h>
#include <stdlib.h>

int main(){


  int numero = 6;
  int *puntero_aNumero = &numero;  // & <<-- direcci[on de memoria de la variable
  
  printf("La puntero puntero_aNumero contiene la direcci[on de memoria: %p \n ", &puntero_aNumero);
  printf("El valor de la variable situada en la direcci[on de memoria a la que apunta es: %d \n", *puntero_aNumero);


  printf("\n");
  //  PUNTERO A STRINGS
  char cadena[30] = "Esta es una cadena de prueba";
  char *puntero_aCadena = &cadena[0];

  for(int i=0; i<30; i++){
    printf("%c", *(puntero_aCadena + i) );
  }

  printf("\n");
  // PUNTERO A ARRAYS
  int vector[5] = {1,2,3,4,5};
  int *puntero_aVector = &vector[0];
  for(int i=0; i<5; i++){
    printf("%d", *(puntero_aVector + i) );
  }

  printf("\n");
  //  PUNTERO A 
  struct mi_registro{
    int num;
    char car;
  };

  struct mi_registro r1;
  struct mi_registro *r2 = &r1;
  (*r2).num = 5;
  r2->car = 'a';

  printf("El campo num de la estructura a la que apunta r2 es: %d \n", (*r2).num );
  printf("El campo car de la estructura r1 es: %c \n", r1.car);


  return 0;
}
