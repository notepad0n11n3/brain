#include <stdio.h>
#include <string.h>

int main(){

  char cadena1[]="Jorge", cadena2[]="ricardo";
  char final[50];

  strcat(final, cadena1);
  strcat(final, "-");
  strcat(final, cadena2);

  printf("%s\n",final);

  return 0;
}
