#include <stdio.h>

#include <stdlib.h>


    //      generar numero rango [A;B]
  //    num = A + rand() % (B - A + 1);
  //
  //                    
  //                    (b - a + 1);   // [5;12]  ( 12 - 5 + 1)  5, 6, 7 ,8 ,9 ,10, 11, 12 = 8 posibilidades
  //
  //              rand() % ( mango ); // el resultado siempre es menor al valor de mango, results < mango
  //
  //          A + ( result );   // desplazamos el resultado A valores para obtener el rango deseado
  //
  //    num = 5 + (0); num= 5+(2);... num = 5+(7);
  //
int main(){

  fprintf(stdout, "\n\t\t Numero aleatorio entre \"5\" y \"93\" \n");
  fprintf(stdout, "\n\tsin una semilla los n[umeros generados ser[an los mismos en cada ejecuci[on del programa\n");
  int num;

  for(int i=1; i<=10; i++){
    num = 5 + rand() % (93-5+1);
    fprintf(stdout, "\n==> %d\n", num);
  }


  return 0;
}
