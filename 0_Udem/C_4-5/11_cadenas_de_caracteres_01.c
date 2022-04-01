#include <stdio.h>
#include <stdlib.h>


int main(){
  char cadena1[50], cadena2[50], cadena3[50], cadena4[50];

  printf("Introduce la cadena 1: ");
  fgets(cadena1, 50, stdin); getchar();
//scanf("%s",cadena1);

  printf("Introduce la cadena 2: ");
  fgets(cadena2, 50, stdin); getchar();
//scanf("%s",cadena2);

  printf("Introduce la cadena 3: ");
  fgets(cadena3, 50, stdin); getchar();
//scanf("%s",cadena3);

  printf("Introduce la cadena 4: ");
  fgets(cadena4, 50, stdin); getchar();
//scanf("%s",cadena4);

  printf("%s-%s-%s-%s",cadena1, cadena2, cadena3, cadena4);

  return 0;
}
