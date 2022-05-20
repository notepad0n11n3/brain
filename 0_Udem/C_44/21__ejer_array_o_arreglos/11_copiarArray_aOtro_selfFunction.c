#include <stdio.h>
#include <string.h>

const int tamalito=80;

void masta(char go1[], char go2[]);

int main(){
  char data1[tamalito], data2[tamalito];

  printf("Ingrese el string: ");
  fgets(data1, tamalito, stdin); strtok(data1,"\n");

  printf("data1 = %s\n",data1);
  printf("data2 = %s\n",data2);

  masta(data1, data2);
  return 0;
}

void masta(char data1[], char data2[]){
  int ty=0;
  for(ty=0; data1[ty] != '\0'; ty++){
    data2[ty] = data1[ty];
  }
  
  printf("\n\t data 2 ==> %s\n",data2);

  printf("\n\t data 1 ==> %s\n",data1);
  
}
