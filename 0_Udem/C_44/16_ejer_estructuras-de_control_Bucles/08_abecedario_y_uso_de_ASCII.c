#include <stdio.h>

int main(){

  char x='a', o='A';

  // 97 -> 122 minusculas
  // 65 -> 90  mayusculas

  do{
    printf("%c ",x);
    x++;
  }while(x<='z');

  do{
    printf("%c ",o);
    o++;
  }while(o<='Z');

  printf("\n------------------------------------------------------------------\n");

  char xMinu=97, oMayu=65;
  do{
    printf("%c ",xMinu);
    xMinu++;
  }while(xMinu <= 122);

  do{
    printf("%c ",oMayu);
    oMayu++;
  }while(oMayu <= 90);
  return 0;
}
