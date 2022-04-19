/* crear array de 100 elementos con n[umeros aleatorios entre 1 y 1000.
 * organizar en 2 arrays, pares y impares.    */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CANTIDAD 100

int main(){
  int numero[CANTIDAD], pares[CANTIDAD], impares[CANTIDAD];

  srand(time(NULL));

  for(int i=0; i < CANTIDAD; i++){
    numero[i]= rand()% +(1000+1);
    printf("%d ",numero[i]);
  }

  for(int i=0; i < CANTIDAD; i++){
    if( (numero[i] % 2) == 0 )
      pares[i] = numero[i];
  }
  
  printf("\n Array Pares...\n");
  for(int i=0; i < CANTIDAD; i++){
    printf(" %d ",pares[i] );
  }
  return 0;
}
