#include <stdio.h>
#include <string.h>

int main(){
  char userData[30];
  int nee=0;

  printf("Ingrese el string: ");
  fgets(userData, 30, stdin); strtok(userData,"\n");

  while( userData[nee] != '\0'){
    nee++;
  }
//for(nee; userData[nee]!='\0'; nee++){}

  printf("\n La palabra %s tiene %d caracteres\n\t", userData, nee);

  while( nee >= 0){
    printf("%c", userData[nee] );
    nee--;
  //printf("%c", userData[nee--] );  // juntamos el nee--;
  }
//for(nee; nee>=0; nee--){printf("%c", userData[nee] );}

  return 0;
}
