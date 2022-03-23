#include <stdio.h>

#include <string.h>

int main(){

  int totalAlumnos=0, mujeres=0, hombres=0;
  char sexo[11];  // con 10 no se suficiente espacio, la palabra masculino rompeDeja floatndo un '\n'

  printf("Ingresa el n[umero total de alumnos: ");
  scanf("%i",&totalAlumnos); getchar();

  for(int i=0; i < totalAlumnos; i++){
    printf("\nIngrese el sexo del alumnos numero %i: ",i+1);
    fgets(sexo, 11, stdin); strtok(sexo, "\n");

    if( strcmp(sexo,"femenino")==0  ){
      mujeres++;
    }else if( strcmp(sexo,"masculino")==0 ){
      hombres++;
    //getchar();    //<<--  Es extra~o, si entra en else if queda suelto un \n.
    }
  }

  printf("\n El total de hombres es de %i",hombres);
  printf("\n El total de mujeres es de %i",mujeres);
  return 0;
}
