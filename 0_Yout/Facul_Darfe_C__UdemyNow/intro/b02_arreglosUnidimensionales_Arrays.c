#include <stdio.h>

    //    
    //
    //    int mango[100] = {0};     // inicia todas las posiciones el array con el valor 0  <3 <3 <3
    //    int test[15000] = {5};     // evita mucha basura de memoria <3 <3
    //    float test2[888777] = {2};
    //
    //    int a[5];     ;a   es lo mismo que  &a[0]
    //      
    //
    //        sumarNumeros(a, b);     // se pasa por referencia el array 'a' sola es igual a &a[0]
    //
    //


int sumaNumeros(int A[], int N);



int main(int argc, char *argv[]){

  int A[100], N, suma;

  fprintf(stdout, "\nIngrese cantidad: ");
  scanf("%d", &N);


  for(int i=0; i<N; i++){
    fprintf(stdout, "\n\t\tIngrese el dato %d: ", i);
    scanf("%d", &A[i]);
  }

  suma = sumaNumeros(A, N);

  fprintf(stdout, "\nLa suma de los numeros es %d\n", suma);

  return 0;
}



int sumaNumeros(int A[], int N){

  int i, suma = 0;

  for(i=0; i<N; i++){
    suma += A[i];
  }

  return suma;
}


//    C[0] es lo mismo que  *(C)   o   C  'sola es una direcci[on de memoria funciona como un puntero a C[0] '
//    C[1] es lo mismo que  #(C+1)
//    C[2] es lo mismo que  #(C+2)
//    C[3] es lo mismo que  #(C+3)
//    C[4] es lo mismo que  #(C+4)
