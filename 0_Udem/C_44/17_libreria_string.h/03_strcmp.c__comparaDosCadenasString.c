#include <stdio.h>
#include <string.h>
#include <stdlib.h>

  //  strcmp(cadena1, cadena2);    // es case-sensitive

int main(){

  char password[]="password";
  char user_data[128];
  int intento_restantes=3;

  system("clear");
  do{
    printf("\n\tIngrese la clave secreat:\n");
    fgets(user_data, 128, stdin); strtok(user_data, "\n");

    // ! validaci[on de la contrase~a
    if( strcmp(password,user_data)==0 ){
      printf("\n\t\t==>> Bienvenido nuevamente al systema U.U...\n");
      break;
    }else{
      intento_restantes--;
      system("clear");
      printf("Clave secreta incorrecta, le quedan: %i intentos\n",intento_restantes);
    }
  }while( intento_restantes > 0);


  return 0;
}
