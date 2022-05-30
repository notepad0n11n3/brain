#include <stdio.h>
                                  //  es equivalente a
                            //      apuntador_Here = array_Here  ===   apuntador_Here = &array_Here[0]

            //   void mi_funcion(int mango[], int 10);          int array_Here[10];
            //   mi_funcion(array_here, size_array);         // por default creo que se pasa por referencia(los cambios afectaran al arrayOriginal)
int main(void){

  int mango[] = {1,2,3,4,5,6,7,8,9,10}, *apuntador_mango;

  apuntador_mango = &mango[2];
  printf("%d", *apuntador_mango);

  apuntador_mango = mango;

  printf("\t\t#=> %d" , *(apuntador_mango + 2) );

        //  *(apuntador_mango + 2)     !=    *p+3

  return 0;
}
