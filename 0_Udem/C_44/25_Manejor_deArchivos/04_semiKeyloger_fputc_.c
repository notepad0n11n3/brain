#include <stdio.h>

int main(void){

  FILE *puntero_Archivo;
  puntero_Archivo = fopen("04_.txt", "a");


  if( puntero_Archivo == NULL ){
    printf("\n\t Error al intentar crear/acceder al archivo\n");
  }else {
    char letra;
    while( (letra = getchar()) != '\n' ){
      fputc(letra, puntero_Archivo);              // Escribe lo que se digite en el archivo like a keyloger
    }
  }

  fclose(puntero_Archivo);
  return 0;
}
