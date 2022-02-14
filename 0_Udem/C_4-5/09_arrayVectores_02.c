#include <stdio.h>
#include <stdlib.h>

//    valor maximo y minimo de un array
int main(){
  int x89p[10]={4,7,9,75,-5,6,12,-10,0,1};
  int maximo = x89p[0];
  int minimo = x89p[0];

  for(int i=1; i<10; i++){
    if(x89p[i] > maximo){
      maximo = x89p[i];
    }

    if(x89p[i] < minimo){
      minimo = x89p[i];
    }
  }

  printf("Valor m[aximo: %d\n Valor m[inimo: %d",maximo,minimo);

  return 0;
}
