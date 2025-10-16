#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  char x89p[100]="Esto es una cadena U.U";   //    acaba en \0
  char x89p2[100]="Esto es una cadena \0";
  char x89p3[100]={'e','s','t','o',' ','e','s',' ','u','n','a',' ','c','a','d','e','n','a','\0'};

  for(int i=0; i<100; i++){
    printf("%c",x89p[i]);
  }
  printf("\n----------------------\n");

  printf("%c",x89p[3]);
  x89p[3]= 'A';
  printf("%c",x89p[3]);
  
  printf("\n----------------------\n");
  printf("%s",x89p2);


  printf("\n\nIntroduce una cadena: ");
  //scanf("%s",x89p); //  solo hasta el espacio
  fgets(x89p, 40, stdin); strtok(x89p, "\n");
  printf("-->> %s",x89p);

  return 0;
}
