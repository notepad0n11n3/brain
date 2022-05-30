#include <stdio.h>

            //   void mi_funcion(int mango[], int 10);          int array_Here[10];
            //   mi_funcion(array_here, size_array);         // por default creo que se pasa por referencia(los cambios afectaran al arrayOriginal)


void mi_Funcion(int mango[][10]);


int main(void){

  int mi_Arreglo[10][10];

  mi_Funcion(mi_Arreglo);
  
  return 0;
}


void mi_Funcion( int mango[][10] ){  // desde el segundo espacio del array se tiene que indicar el tama;o para que el compilador reserve espacio en memoria
//void mi_Funcion( int mango[10][10] ){    

}


void mi_Funcion( int mango[][10][10] ){
}
