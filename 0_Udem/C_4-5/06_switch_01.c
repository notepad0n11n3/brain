#include <stdio.h>
#include <stdlib.h>


int main(){

  system("clear");
  int user_data;

  printf("\n\tIngrese un n[umero del 1-7: ");
  scanf("%d",&user_data);


  switch(user_data){
    case(1):
      printf("\nYour choose is 1  ");
      break;
    case(2):
      printf("\nYour choose is 2  ");
      break;
    case(3):
      printf("\nYour choose is 3  ");
      break;
    case(4):
      printf("\nYour choose is 4  ");
      break;
    case(5):
      printf("\nYour choose is 5  ");
      break;
    case(6):
      printf("\nYour choose is 6  ");
      break;
    case(7):
      printf("\nYour choose is 7  ");
      break;
    default:
      printf("\n\t\t\t Error... Fucking noob.   U.U");
      break;
  }

  return 0;
}
