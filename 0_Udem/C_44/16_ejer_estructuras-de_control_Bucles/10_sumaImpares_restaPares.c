#include <stdio.h>

int main(){

  int sumaTotal, sumaPares=0, sumaImpares=0, user_number;
  int numeroNegativo=0;

  printf("Ingresa el n[umero:\n");
  scanf("%d",&user_number); getchar();

  printf("%d=<",user_number);
  for(int i=1; i<=user_number; i++){
    if((i%2)==0){
      numeroNegativo = i * -1;
      sumaPares += numeroNegativo;
    }else {
      sumaImpares += i;
    }
  }
  sumaTotal = sumaImpares + sumaPares;

  printf("La suma de los n[umeros pares es: %d\n", sumaPares);
  printf("La suma de los n[umeros impares es: %d\n",sumaImpares);
  printf("El resultado es: %d\n",sumaTotal);

  return 0;
}

/*
-1+2-3+4-5+6
-12+9
-3
*/
