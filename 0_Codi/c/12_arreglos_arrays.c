
    //  ARREGLO === ARRAY   

#include <stdio.h> // directiva include 

    // PRIMERO ASIGNA LA CANTIDAD DE DATOS QUE TENDRA EL ARRAYS[8], despues agrega los datos USANDO LAS POSICIONES  ..............

//funci[on main inicia la ejecuci[on del programa
int main()
{
  /*
  int arreglo[4] = {3,4,1,5};  // arrays para 4 elementos
  printf("%i \n", arreglo[2]);
  */

  // OBTENEMOS EL TAMANO DEL ARREGLO en input del usuario

  int siseA;
  printf("\tTamano del arreglo\n");
  scanf("%i", &siseA);
  int age[siseA];

  for (int i = 0; i < siseA; i++)
  {
    printf("Ingresa el valor %i \n", i + 1);
    scanf("%i", &age[i]);
  }
  printf("Los valores del arreglo son: \n");
  for(int i = 0; i < siseA; i++)
  {
    printf("%i-\n", age[i]);
  }
  return 0; // indica que el programa se termin[o con exito
}
