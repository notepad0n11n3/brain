#include <stdio.h>
#include <string.h>
#include <time.h>

time_t begin, end;

int main(void){

  char user_info[88];
  begin = time(NULL);

  printf("\nIngrese el nombre de usuario please: ");
  fgets(user_info, 88, stdin); strtok(user_info, "\n");

  end = time(NULL);

  printf("\n\t Bienvenido %s de vuelta, demoraste %2.2f... que LENTO :U\n", user_info, difftime(end, begin) );
  return 0;
}
