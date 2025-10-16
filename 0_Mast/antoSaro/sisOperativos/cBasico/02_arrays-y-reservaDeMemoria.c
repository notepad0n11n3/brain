#include <stdio.h>
#include <stdlib.h>

      /*   STACK Y HEAP
       *   el Heap es la zona de memoria que te asigna el sistema para poder almacenar variables o datos para tener acceso a ellas desde cualquier funcion (variablesGlobales)
       *   
       *   el stack es la zona de mamoria donde se almacenan las variables locales(noGlobales) que suelen pertenecer [unicamente a la funci[on padre.   EL STACK SUELE SER LIMITADO, para usar tama~os grandes usamos el Heap (creamos punteros al hip) importando la libreria stdlib.h  (malloc)
       */

int main() {
//  int arrayDesu[] = {1, 2, 3, 4, 5, 6, 7, 8};
  int *arrayDesu = malloc(sizeof(int) * 8);
  for ( int go = 0; go < 8; go++){
    arrayDesu[go] =  go + 1;
  }

  for ( int ro = 0; ro < 8; ro++){
    printf("Valor de array[%i] = %i \n", ro, arrayDesu[ro]);
  }

  arrayDesu[0] = 12;
  printf("---Valor de array[0]: %i \n", arrayDesu[0]);


                          // error al tratar de acceder a una zona de memoria no asignada
  arrayDesu[100000] = 5;  // zsh: segmentation fault  ./a.out

  //CUANDO DECLARAS UN PUNTERO TIENES QUE LIBERAR LA MEMORIA DESPU[ES PARA NO CAUSAR UN LEAKE, liberar esa zona de memoria
  free(arrayDesu);

}
