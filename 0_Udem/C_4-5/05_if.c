#include <stdio.h>
#include <stdlib.h>


int main(){
  int number_One=3;
  int number_Two=8;
  int number_Ttt=5;

  if(number_One > 0 && number_Two > 0){
    if(number_Ttt > 0){
      printf("Los 3 n[umeros son positivos\n");
    }
  }
  else if(number_One > 0 || number_Two > 0){
    printf("Alguno de los n[umeros es positivo\n");
  }
  else{
    printf("Ninguno de los n[umeros es positivo");
  }

  return 0;
}
