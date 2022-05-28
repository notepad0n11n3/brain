#include <stdio.h>


                              //       &vector[i]   ==== puntero_aVector

int main(void){

  int vector[] = { 12, 22, 31, 49, 51, 62, 73, 81, 99, 10};

  int *puntero_aVector = vector;   // POR DEFECTO EL PUNTERO APUNTA A LA POSICI[ON 0   <3 <3 <3 <3 <3 <3 <3

  for(int i=0; i<10; i++){

    printf("\nDato vector: %d", vector[i]);
    printf("\nDirecci[on de memoria de vector[%d]: %p", i, &vector[i] );
    printf("\nDirecic[on de memoria de vector[%d]: %p", i, puntero_aVector);

    puntero_aVector++;        // por default el puntero mostrara la posici[on 0 del array, tenemos que recorrer el puntero con ++  <3 <3 <3 


    printf("\n\n puntero_aVector: %p  %d", puntero_aVector, puntero_aVector);      // direcci[on de memoria deLo qApunta, el primerIndice del vector
    printf("\n&puntero_aVector: %p  %d", &puntero_aVector, &puntero_aVector);      // direcci[on de memoria DEL APUNTADOR...!!!
    printf("\n*puntero_aVector: %p  %d\n", *puntero_aVector, *puntero_aVector);    
  }

  return 0;
}
