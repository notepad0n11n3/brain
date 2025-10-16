#include <stdio.h>
#include <stdlib.h>

double kelvin(float goro);
double fahrenheit(float goro);
void menu();

int main(){
  menu();
  return 0;
}

void menu(){
  int option=1, user_option;
  float user_data;
  do{
    printf("Ingrese la temperatura:\n");
    scanf("%f",&user_data); getchar();

    printf(" 1) Kelvin\n 2) Fahrenheit\n 3) Salir\n");
    scanf("%d",&user_option); getchar();

    switch(user_option){
      case 1: printf(" El valor es: %.2f\n",kelvin(user_data)); break;
      case 2: printf(" El valor es: %.2f\n",fahrenheit(user_data)); break;
      case 3: option=0; break;
      default: system("clear");printf("\n\t\t Error... opci[on inv[alida.\n");
    }
  }while(option!=0);
}

double kelvin(float goro){
  float resultado = 0;
  resultado = goro + 273.15;
  return resultado;
}

double fahrenheit(float goro){
  float resultado = 0;
  resultado = (goro*9)/5 + 32;
  return resultado;
}
