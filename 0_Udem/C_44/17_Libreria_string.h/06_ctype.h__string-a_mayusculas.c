#include <stdio.h>

#include <string.h>
#include <ctype.h>

int main(){

  char user_data[200];

  printf("Ingresa una cadena: \n");
  fgets(user_data, 200, stdin);strtok(user_data,"\n");//strtok(variable,caracterLimitador); string.h

  for(int i=0; user_data[i] != '\0'; i++){
    user_data[i] = toupper( user_data[i] );
  }

  printf("El nuevo texto es el siguiente:\n");
  printf("%s\n",user_data);

  return 0;
}
