#include <stdio.h>

int main(){
  int i;

  printf("Introduce un n[umero(int): \n");
  scanf("%i",&i);

  printf("El n[umero es=> %i\n",i);
  printf("Direcci[on de memoria=> %p\n",&i);
  printf("p sin & DireccionMemoria=> %p\n",i);

  return 0;
}
