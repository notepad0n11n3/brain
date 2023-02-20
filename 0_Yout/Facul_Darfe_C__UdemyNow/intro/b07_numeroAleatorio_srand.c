#include <stdio.h>

#include <stdlib.h>

  //      user_random = user_firts + rand() % (user_last - user_firts + 1);



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

#include <time.h>

int main(){

  fprintf(stdout, "\n\t\t Numero aleatorio entre \"5\" y \"93\" \n");

  int num;
  srand(time(NULL));  // semilla para numero aleatorio en cada ejecuci[on de programa compilado <3  
                      // inicializa srand UNA sola vez por programa. 

  for(int i=1; i<=10; i++){
    num = 5 + rand() % (93-5+1);

  //  aleatorio  =  primer_numero  +  rand()  %  (segundo_numero  -  primer_numero  +  1);

    fprintf(stdout, "\n==> %d\n", num);
  }


  return 0;
}
