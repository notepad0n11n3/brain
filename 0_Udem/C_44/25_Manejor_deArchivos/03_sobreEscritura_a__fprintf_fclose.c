#include <stdio.h>

int main(void){

  FILE *puntero_Archivo;
  puntero_Archivo = fopen("03.txt", "a");

  if( puntero_Archivo == NULL ){
    printf("\n\tEl archivo no existe :(");   // esto nunca se va a ejecutar, "a" crea automaticamente el archivo y agrega el texto al final.
  }else {
    printf("\n\t\t Archivo encontrado... Agregando datos... <3 <3 <3\n");
    char texto[] = "Mango caliente csm";
    fprintf(puntero_Archivo, "Texto Generico: %s\n", texto);
  }

  fclose(puntero_Archivo);

  return 0;
}
