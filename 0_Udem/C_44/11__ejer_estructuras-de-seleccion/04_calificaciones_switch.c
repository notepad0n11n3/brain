#include <stdio.h>

int main(){
  int nota;

  printf("Digita tu calificaci[on: \n");
  scanf("%d",&nota);

  switch(nota){
    case 1: printf("Reprobado :( "); break;
    case 2: printf("Reprobado :( "); break;
    case 8: printf(" Aprobado :) "); break;
    case 9: printf(" Aprobado :) "); break;
    default: printf(" Opcion inv[alida :( "); break;
  }
  return 0;
}
