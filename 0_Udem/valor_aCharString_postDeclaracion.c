#include <stdio.h>
#include <string.h>

int main(){

  char nombre[20];
  strcpy(nombre,"manolo");
  printf("=>>%s",nombre);


  struct molde{
    char nombreDes[80];
  };
  struct molde test1;

  strcpy(test1.nombreDes, "stringA_structPostDeclaraci[on");

  printf("\n -=> %s",test1.nombreDes);

  return 0;
}
