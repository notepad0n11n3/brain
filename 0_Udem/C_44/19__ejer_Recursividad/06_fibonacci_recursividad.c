#include <stdio.h>

int fibo(int numero);
int main(){
  int user_number, xtraSumaTotal=0;
  printf("Ingrese el n[umero: ");
  scanf("%d",&user_number); getchar();

  
  for(int i=1; i<=user_number; i++){
    printf("%d  ", fibo(i) );
    xtraSumaTotal += fibo(i) ;
  }
  
  printf("\n\t\t => %d\n", xtraSumaTotal);
  return 0;
}

int fibo(int des){
  if(des == 1 || des == 2){
    return 1;
  }else {
    return ( fibo(des-1) + fibo(des-2) );
  }
}

//*  1 1 2 3 5 8 13 21 34 55
//*
//*    fibonacci(1) = 1
//*    fibonacci(2) = 1
//*    fibonacci(3) = 2
//*    fibonacci(4) = 3
//*    fibonacci(5) = 5
//*    fibonacci(6) = 8
//*    fibonacci(7) = 13
//*    fibonacci(8) = 21
//*    fibonacci(9) = 34
//*    fibonacci(10) = 55
//* /
