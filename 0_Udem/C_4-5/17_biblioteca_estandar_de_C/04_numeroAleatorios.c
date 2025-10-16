#include <stdio.h>
#include <stdlib.h>

#include <time.h>

int main(){

  srand(time(NULL));   // generamos una semilla
  printf("%d\n", rand() % 11);
}
