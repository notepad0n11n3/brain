#include <stdio.h>

int main(){
  int array[3]={24,5,88};

  printf("\t=>%p\n\n", array); //direcci[on de memoria

  printf("Primer valor del array=%d\n",array[0]);
  printf("Segundo valor del array=%d\n",array[1]);
  printf("Tercer valor del array=%d\n",array[2]);

  //modificamos un valor del array
  array[0]=1234;
  printf("\nEl nuevo valor del primer elemento del array es: %d\n",array[0]);
  return 0;
}
