#include <stdio.h>

  // continue  sirve para terminar una iteraci[on y pasar a la siguiente
  // break     no solo termina con una iteraci[on, sino con el ciclo completo
int main(){

  int numero;

  printf("Escribe el n[umero que ser[a ignorado: \n");
  scanf("%d",&numero); getchar();

  for(int i=0; i<10; i++){
  //if(i==numero){ continue; }
    if(i==numero){
      continue;
    }
    printf("Hello %d\n",i);
  }

  for(int i=0; i<10; i++){
  //if(i==numero){ break; }
    if(i==numero){
      break;
    }
    printf("Kiss %d\n",i);
  }

  return 0;
}
