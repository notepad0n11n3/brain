#include <stdio.h>

#include <string.h>

int main(){
  char *x89p;
  char c[40];
  printf("Ingrese un string: \n");
//scanf("%s",&c);     // corta al encontrar el primer espacio

  fgets(c, 40, stdin);
  x89p = strchr(c, 10);
  if(x89p != NULL){
    *x89p = '\0';
  }

  printf("Hello %s\n",c);
  return 0;
}
