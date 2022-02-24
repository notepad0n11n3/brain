#include <stdio.h>

int main(){
  int des[10];

  for(int i=0; i< 10; i++){
    printf("Ingresa el valor para la posici[on %d del array => \n",i);
    scanf("%d",&des[i]); getchar();
  }

  int indice=-1;

  while(++indice < 10){    //    uso interesante del pre/post..incremento   ++i   i++
    printf("%d ", des[indice] );
  }


  return 0;
}
