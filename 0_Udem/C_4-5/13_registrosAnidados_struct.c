#include <stdio.h>
#include <stdlib.h>

int main(){

  struct tipo1{
    int entero1;
    char caracter1;
  };

  struct tipo1 qpqpqp;
//struct tipo1 qpqpqp = {5,'a'};   //  { int , char }
  qpqpqp.entero1 = 5;

  struct tipo2{
    float real1;
    struct tipo1 variable1;
  };

  struct tipo2 variable2;
//struct tipo2 variable2 = {5.5,{7,'a'}}; // { float ,{ int, char } }
  variable2.real1 = 5.5;
  variable2.variable1.entero1 = 7;

  printf("%d",variable2.variable1.entero1);


  return 0;
}
