#include <stdio.h>

int main(){
  int materias_Reprobadas;

  printf("Ingresa el n[umero de materias reprobadas:\n");
  scanf("%i",&materias_Reprobadas);

  if(materias_Reprobadas <= 3){
    printf("Pasar al siguiente a;o\n");
    if(materias_Reprobadas != 0){
      printf("Debes %d materias <==\n",materias_Reprobadas);
    }
  }else if(materias_Reprobadas > 3){
    printf("Volver a cursar el a;o\n");
  }else{
    printf("...Dato invalido... :(\n");
  }
  return 0;
}
