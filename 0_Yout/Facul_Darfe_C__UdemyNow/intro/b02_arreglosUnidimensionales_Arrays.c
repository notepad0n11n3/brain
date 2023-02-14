#include <stdio.h>

    //    
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
