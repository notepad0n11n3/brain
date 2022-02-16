#include <stdio.h>

#include <string.h>

int main(){
  char nombre[30], sexo[10];
  int edad;

  printf("Ingrese su nombre:\n");
  fgets(nombre, 30, stdin);
  strtok(nombre,"\n");  //   string.h

  printf("Ingrese su edad:\n");
  scanf("%d",&edad);
  getchar();  printf("La edad es %d\n",edad);

  int x89p;
  printf("Ingresa otro n[umero por si las dudas: \n");
  scanf("%d",&x89p);
  getchar();    printf("El otro n[umero por si acaso es %d\n",x89p);


  printf("Ingrese su sexo:\n");
  fgets(sexo, 10, stdin);
  strtok(sexo,"\n");


  if( (strcmp(sexo,"femenino") == 0) && (edad <= 18) ){
    printf("\n\t=>Cumple con los requisitos: %s",nombre);
  }else{
    printf("\n\t=> No cumple con los requisitos :(");
  }
  return 0;
}
