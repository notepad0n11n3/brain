/*
 *  Directivas del Preprocesador 
 */

//si elNombre del archivoESTA ENTRE <> EL preprocesador buscara en los encabezados de la biblioteca standard, si estaEntre "" elPreprocesador buscara en el mismo directorio donde se encuentra el archivo que va a compilarse
#include <stdio.h> 
// #include "stdioSauron.h"  :: #include "nombreDelArchivo"   
#define PIsauron 3.14159

// MACRO MACRO MACRO...    las macros son m]aas r]apidas que una funcion, se ahorra mucho al no tener que estar llamando a una funcion
#define CUBOx89p(sauron) sauron*sauron*sauron

int main()
{
  int suma;
  suma = PIsauron + 3;

  int  sauron=4;

  printf("%i \n", suma);  // %i  espera un entero :)
  printf("El cubo de nuestra variable sauron es : %i\n",CUBOx89p(sauron));

  return 0;
}
