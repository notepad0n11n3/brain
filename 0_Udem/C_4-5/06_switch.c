#include <stdio.h>
#include <stdlib.h>


int main(){
  int n = 2;

  switch(n){
    case(1):
      printf("La variable contiene 1");
      break;
    case(2):
      printf("La variable contiene 2");
      break;
    case(3):
      printf("La variable contiene 3");
      break;
    default:
      printf("La variable no contiene los valores 1, 2 [o 3  :( ");
      break;
  }


  return 0;
}
