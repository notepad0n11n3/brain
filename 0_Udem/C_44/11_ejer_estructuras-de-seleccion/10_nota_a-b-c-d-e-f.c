#include <stdio.h>
#include <string.h>

int main(){
  char user_data;

  printf("Ingrese su calificaci[on ( a,b,c,d,e,f )\n");
  scanf("%c",&user_data);

  switch(user_data){
    case 'a':
      printf("Excelente... aprobado\n");
      break;
    case 'b':
      printf("Notable... aprobado\n");
      break;
    case 'c':
      printf("Aprobado... por poco");
      break;
    case 'd':                           //  NO ES UN ERROR, d y f ejecutan el mismo codigo :) <3
    case 'f':
      printf("Reprobado... T.T\n");
      break;
    default:
      printf("....OPCI[ON INV[ALIDA...!!!");
      break;
  }
  return 0;
}
