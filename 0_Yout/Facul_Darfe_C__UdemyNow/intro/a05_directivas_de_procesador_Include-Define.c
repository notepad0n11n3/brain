        // DIRECTIVAS DEL PROCESADOR
        //
          // entre < >  directivas por defecto 
          // libreria que esta en el directorio por defecto de C
#include <stdio.h>
#include <unistd.h>

          // entre " "
          // libreria propia o descargada en la carpeta del proyecto
#include "a05_mi_directiva.h"
#include "./a05_mi_directiva.h"


// funcion con macro <3 <3 <3 ...
#define MOSTRAR(X)  printf("%s", X);
#define MANGO 22

int main(int argc, char *argv[]){

  MOSTRAR("Mensaje generico <3");
  
  fprintf(stdout, "\n\t \"mango=>%d\"\n", MANGO);

  return 0;
}
