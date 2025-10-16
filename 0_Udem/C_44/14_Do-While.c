#include <stdio.h>

int main(){

  int x=1;
          // se ejecuta 1 vez, despu[es verifica si la sentencia es verdadera x>10
  do{
    printf("Hello %d\n",x);
    x++;
  }while(x>10);

  return 0;
}
