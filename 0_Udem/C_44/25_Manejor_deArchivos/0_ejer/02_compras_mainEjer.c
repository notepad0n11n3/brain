#include <stdio.h>
#include <stdlib.h>

#define address "compras.txt"

void my_function();
void add_toFile();

int main(void){

  FILE *apuntador_Archivo;
  apuntador_Archivo = fopen(address, "a");

  int dingoo=0;
  while( dingoo == 0 ){
    printf("\n\tLista de compras:...\n");

    int user_option;
    printf("\n\tIngrese una opci[on:   1)Agregar  2)Mostrar Lista  3)Salir\n");
    scanf("%d", &user_option); getchar();

    switch( user_option ){
      case 1: 
        add_toFile();
        break;
      case 2:
        my_function();
        break;
      case 3:
        system("clear");
        printf("\n\t\t\t Saliendo... ... ...\n");
        dingoo = 1;
        break;
      default: 
        system("clear"); printf("\n\n\t\t\t\tWRONG OPTION WRONG OPTION WRONG OPTION\n");
        break;
    }
  }
  fclose(apuntador_Archivo);

  return 0;
}

void add_toFile(){
  FILE *apuntador_Archivo = fopen(address, "a");
  char mango;
  printf("Agrege algo a la lista..\n\t::> ");
  while( (mango=getchar()) != '\n' ){
    fputc(mango, apuntador_Archivo);
  }
  fputc('\n', apuntador_Archivo);
  system("clear");
  fclose(apuntador_Archivo);
}
void my_function(){
  system("clear"); printf("\n"); 
  system("cat compras.txt"); printf("\n");
}

