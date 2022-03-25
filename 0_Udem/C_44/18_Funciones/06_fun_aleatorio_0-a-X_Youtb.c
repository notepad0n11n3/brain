#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

  int user_number, numeroAleatorio;
  printf("Ingrese el limite para los n[umero aleatorios:\n");
  scanf("%d",&user_number); getchar();

  srand(time(NULL));
  numeroAleatorio= rand() % (user_number + 1);

  printf("=> %d",numeroAleatorio);


  printf("\n\tRandom number 0-3: %d\n", rand()%4);
  return 0;
}
