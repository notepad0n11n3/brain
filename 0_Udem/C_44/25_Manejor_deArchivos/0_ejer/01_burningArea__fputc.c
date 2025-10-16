#include <stdio.h>
#include <stdlib.h>

int main(void){

  FILE *apuntador_Archivo;
  apuntador_Archivo = fopen("keyloger.txt", "a");

  char mango;
  while( (mango = getchar()) != '\n' ){
    fputc(mango, apuntador_Archivo);
  }
  fputc('\n', apuntador_Archivo);

  fclose(apuntador_Archivo);

  char user_Option;
  printf("Desea leeer el archivo?  Y/y  N/n  \t");
  scanf("%c", &user_Option);

  switch(user_Option){
    case 'y':
    case 'Y':
      printf("\n\t Abriendo el archivo...\n"); system("clear && sleep 1");
      system("cat keyloger.txt");
      break;
    case 'n':
    case 'N':
      printf("\n\nSaliendo..."); system("sleep 1");
      break;
    default:
      printf("\nSaliendo...   opci[on incorrecta\t :( \n");
      break;
  }

  return 0;
}
