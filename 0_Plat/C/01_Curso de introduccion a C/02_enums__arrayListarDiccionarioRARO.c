#include <stdio.h>

enum weekDays { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};

enum goroNe {
  club=0,
  diamonds=5,
  hearts=10,
  spades=15
} snowBall;

int main(){

  snowBall = spades;
  printf("\n\t=> %d\n",snowBall);
  printf("\tSize of var %d\n", sizeof(snowBall) );

  enum weekDays today;
  today = Wednesday;

  printf("\t Day %d\n", today+1);

  return 0;
}
