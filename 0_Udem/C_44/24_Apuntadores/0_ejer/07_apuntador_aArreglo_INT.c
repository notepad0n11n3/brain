#include <stdio.h>
                                  //  es equivalente a
                            //      apuntador_Here = array_Here  ===   apuntador_Here = &array_Here[0]

            //   void mi_funcion(int mango[], int 10);          int array_Here[10];
            //   mi_funcion(array_here, size_array);         // por default creo que se pasa por referencia(los cambios afectaran al arrayOriginal)
int main(void){
  int numero[4], *apuntador_Numero;

//apuntador_Numero = &numero[0];
  apuntador_Numero = numero;     // no usamos el & al ser un array, apuntara por defecto a la primera posisic[on del arreglo

  for(int i=0; i<4; i++){
    printf("\nIngrese el valor %d: ", i);
    scanf("%d", &numero[i]); getchar();
  }

  for(int i=0; i<4; i++){
    if( *apuntador_Numero % 2 == 0 ){
      printf("\nEl numero %d es par", *apuntador_Numero);
      printf("\nLa direcci[on de memoria es %p", apuntador_Numero);
      printf("\tLa direcci[on de memoria es %p\n", &numero[i]);
    }
    apuntador_Numero++;
  }

  return 0;
}

#include <stdio.h>

int main(void){

  int mi_array[4], *mi_apuntador;

  mi_apuntador = mi_array;

  for(int i=0; i<4; i++){
    printf("\nIngrese el valor %d: ", i);
    scanf("%d", mi_apuntador); getchar();
    mi_apuntador++;
  }

  (1 == 1)? printf("\n=> ") : printf("else Ready") ;

  mi_apuntador = mi_array;                             // por alguna razon el apuntardor se queda en la posicion 3 del array, asignamos otra vez el puntero a la variable para que este apunte a la posici[on[0] por defecto
  for(int i=0; i<4; i++){
    printf(" %d ", *mi_apuntador);
    mi_apuntador++;
  }
  return 0;
}
