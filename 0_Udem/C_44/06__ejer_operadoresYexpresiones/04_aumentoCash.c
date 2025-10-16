#include <stdio.h>

#include <string.h>

int main(){
  char *umu;
  char nombre[50];
  int salario;
  float aumentoSalario;

  // INGRESAR NOMBRE
  printf("Inserte su nombre por favor:\n");
//gets(nombre);
  fgets(nombre, 50, stdin);
  umu = strchr(nombre, 10);

  if(umu != NULL){
    *umu = '\0';
  }

  printf("Su nombre es: %s\n",nombre);

  printf("Ingrese su salario: \n");
  scanf("%i",&salario);

  printf("Tu salario es: %i\n",salario);

  //aumentoSalario = ((salario * 10)/100) + salario;
  aumentoSalario = (salario*.1)+salario;
  printf("Tu salario ahora es: %.3f", aumentoSalario);

  return 0;
}
