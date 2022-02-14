#include <stdio.h>
#include <stdlib.h>

// Multiplicar del 0 al 10 el n[umero ingresado y escribir el resultado en un archivo
int main(){
  int numero;
  printf("Introduce un n[umero: \n");
  scanf("%d", &numero);  // no \n no \n no \n   NO \n  rompe el codigo

  FILE *f;
  f = fopen("tabla.txt","a");  // si el fichero no existe lo crea
//f = fopen("tabla.txt","w");  // si el fichero no existe lo crea
  for(int i=0; i<=10; i++){
    fprintf(f,"%d\n",i * numero);
  }

  fclose(f);

  return 0;
}
