#include <stdio.h>

int brain(); void intro(); int mango();

int user_number;

int main(){
  intro();

  for(int i=1; i<=user_number; i++){
    printf(" %d ", mango(i) );
  }
  
  return 0;
}

void intro(){
  printf("Ingrese un n[umero:\n");
  scanf("%d",&user_number); getchar();
}

int mango(int des){
  if(des==0 || des==1){
    return des;
  }else {
    return ( mango(des-1) + mango(des-2) );  // 1 1 2 3 5 8 12 21
                                             // mangop(des-1)  se refiere a la posici[on de los n[umeros, no a la resta en si de un n[umero - 1 o 2
  }
}
/*
 *    fibonacci(1) = 1
 *    fibonacci(2) = 1
 *    fibonacci(3) = 2
 *    fibonacci(4) = 3
 *    fibonacci(5) = 5
 *    fibonacci(6) = 8
 *    fibonacci(7) = 13
 *    fibonacci(8) = 21
 *    fibonacci(9) = 34
 *    fibonacci(10) = 55
 * /
