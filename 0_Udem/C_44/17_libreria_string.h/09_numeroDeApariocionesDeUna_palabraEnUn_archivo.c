#include <stdio.h>
#include <string.h>

int main(){

  FILE* Archivo = fopen("Prueba.txt","r");
  int apariciones = 0;   //  Es el contador

  if(Archivo == NULL){
    printf("\n\tError al intentar acceder al archivo\n");
  }else {
    char textoRecibido[1000];
    char palabraBuscada[]="manguito"; 

    while( fscanf(Archivo,"%s",textoRecibido) != EOF){
      if( strcmp(textoRecibido,palabraBuscada) == 0 ){
        apariciones++;
      }
    }
  }

  fclose(Archivo);
  printf("Apariciones de la palabra : %d\n",apariciones);

  return 0;
}
