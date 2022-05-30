#include <stdio.h>

int main(void){

  FILE *mango;

//char direccion[] = "E:\\carpeta_Here\\archivo_Here.txt" ;
  char direccion[] = "/home/aeo8/Desktop/brain/0_Udem/C_44/25_Manejor_deArchivos/02_test.txt";

  mango = fopen(direccion, "r");  // "r" = read 

  if (mango == NULL){
    printf("El archivo no existe\n");
  }else {
    printf("Se encontro el archivo\n");
    printf("Su ubicaci[on es: %s\n", direccion);
  }

  return 0;
}
