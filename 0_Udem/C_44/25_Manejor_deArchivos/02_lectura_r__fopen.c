#include <stdio.h>

int main(void){

  FILE *mango;

//char direccion[] = "E:\\carpeta_Here\\archivo_Here.txt" ;
  char direccion[] = "/home/aeo8/Desktop/brain/0_Udem/C_44/25_Manejor_deArchivos/02.txt";

  mango = fopen(direccion, "r");  // "r" = read 

  if (mango == NULL){
    printf("\n\tEl archivo no existe\n");
    printf("\n\t\t :(   %s <--!!!\n", direccion);
  }else {
    printf("\n\tSe encontro el archivo\n");
    printf("\n\tSu ubicaci[on es: %s\n", direccion);
  }

  fclose(mango);

  return 0;
}
