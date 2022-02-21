#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
  srand(time(NULL));   // srand();  stdlib.h   // time();  time.h
  printf("=>%d", rand() );  // rand();    stdlib.h
            // rand() es la variable que guarda el numero aleatorio generado




  printf("\n=>%d", RAND_MAX); // solo muestra el n[umero maximoAleatorio de srand
}
