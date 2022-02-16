#include <stdio.h>

#include <string.h>
int main(){

  char nombre[20], signo[20];

  printf("Ingresa tu nombre:\n");
  fgets(nombre, 20, stdin);   //     STDIO.H     FGETS(VAR, tamanoArray, stdin)   stdio.h
  strtok(nombre,"\n");

  printf("Ingresa tu password:\n");
  fgets(signo, 20, stdin);
  strtok(signo,"\n");       //    string.h   strtok();   string.h

  if(strcmp(signo,"secret") == 0){ //  strcmp(string1,string2)    string.h  STRING.H
    printf("Su nombre es: %s\n", nombre);
    printf("...==>> Bienvenido...\n");
  } else{
    printf("Su nombre es: %s\n", nombre);
    printf(".Error...  Contrase~a incorrecta\n");
  }
  return 0;
}
