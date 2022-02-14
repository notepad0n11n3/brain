#include <stdio.h>
#include  <stdlib.h>

#include <string.h>   //    strcpy(varCadena, "txtCadena");

int main(){

  struct x89p{
    int dato_entero;
    float dato_float;
    char dato_cadena[30];
    int dato_vector[10];
  };        //  <<< --- <<< --- <<< ---     ;   ;   ;

  struct x89p variable;

  variable.dato_entero=20;
  variable.dato_float=5.5;

  strcpy(variable.dato_cadena, "goro goro des..."); // #include <string.h>
  variable.dato_vector[0]=4;


  printf("El dato de tipo float de mi registro es: %.2f\n",variable.dato_float);

  struct x89p panda8hat[10];

  panda8hat[0].dato_entero=7;
  printf("El dato de tipo entero del primer elemento del vector es: %d",panda8hat[0].dato_entero);

  return 0;
}
