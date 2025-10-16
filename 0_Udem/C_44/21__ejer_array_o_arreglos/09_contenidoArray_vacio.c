#include <stdio.h>
#include <string.h>

#define TAM 20
int main(){
  char dato1[TAM], dato2[TAM];

  printf("dato1 => %s\n",dato1);
  printf("dato2 => %s\n",dato2);

  for(int i=0; i<TAM; i++){
    printf("\n array[%d] = %d",i,dato1[i]);
  }

  printf("\nIngrese el primer string: ");
  fgets(dato1, TAM, stdin); strtok(dato1,"\n");
  printf("\nIngrese el segundo string: ");
  fgets(dato2, TAM, stdin); strtok(dato2,"\n");

  printf("dato1 -> %s\n",dato1);
  printf("dato2 -> %s\n",dato2);

  for(int i=0; i<TAM; i++){
    printf("\n array[%d] = %d",i,dato1[i]);
  }

  return 0;
}
