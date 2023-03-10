#include <stdio.h>

// por defecto el enum inicia las posiciones desde 0
// se puede modificar el valor de inicio asignando un valor a la primera variable o a una variable en cualquier posici[on <3


//enum boolean{FALSE, TRUE};           // las 2 versiones son validas <3
typedef enum{FALSE, TRUE} boolean;

typedef enum{LUNES=1, MARTES, MIERCOLES, JUEVES, VIERNES, SABADO, DOMINGO} dias;

int main(int argc, char *argv[]){

//enum boolean b;     // las 2 versiones son validas <3
  boolean b;

  b=FALSE;

  dias d;

  for(d=LUNES; d<=DOMINGO; d++){ // asignas d = 0 (LUNES)
    fprintf(stdout, "%d", d);
  }

  return 0;
}
