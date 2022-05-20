#include <stdio.h>
#include <stdlib.h>

float celsius_a_Fahrenheit(float orange);
float celsius_a_Kelvin(float movistar);

int main(){

  float user_data;
  int opcionElegida;

  do{
    printf("Ingrese la temperatura:\n");
    scanf("%f",&user_data); getchar();

    printf(" 1) a Fahrenheit\n 2) a Kelvin\n 3) SALIR\n");
    scanf("%d",&opcionElegida); getchar();

    switch(opcionElegida){
      case 1: printf("%.2f grados Celsius son %.2f grados Fahrenheit\n",user_data, celsius_a_Fahrenheit(user_data) ); break;
      case 2: printf("%.2f grados Celsius son %.2f grados Kelvin\n", user_data, celsius_a_Kelvin(user_data) ); break;
      case 3: system("clear"); printf("\n\n\t Saliendo..."); break;
      default: printf("\n\t error... Opci[on inv[alida.\n"); break;
    }

  }while(opcionElegida != 3);

  return 0;
}

float celsius_a_Fahrenheit(float datoRecibido){
  float resultado;
  resultado = (9*datoRecibido)/5 + 32;
  return resultado;
}

float celsius_a_Kelvin(float datoRecibido){
  float resultado;
  resultado = datoRecibido + 273.15;
  return resultado;
}
