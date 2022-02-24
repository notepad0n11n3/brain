#include <stdio.h>
#include <stdlib.h>
// Funciones
void menu(); void sumar(); void restar(); void dividir(); void multiplicar();
// Variables 
int option=1;

int main(){
  do{
    menu();
  }while(option == 1);
  return 0;
}

void menu(){
  int camino;
  printf("\n\tIngresa una opci[on:\n");
  printf(" 1) Sumar\n 2) Restar\n 3) Dividir\n 4) Multiplicar\n 5) Salir\n\n");
  scanf("%d",&camino); getchar();

  switch(camino){
    case 1: sumar(); break;
    case 2: restar(); break;
    case 3: dividir(); break;
    case 4: multiplicar(); break;
    case 5: system("clear"); printf("\n\t\t Saliendo del programa..\n");option = 2; break;
    default: printf("\n\t\t Opci[on invalida, intente nuevamente.\n"); break;
  }

}

void sumar(){
  int number1,number2,resultado=0;
  printf("Ingresa 2 n[umeros:\n");
  scanf("%d %d",&number1, &number2); getchar();
  resultado = number1 + number2;
  printf("=> La suma de %d y %d es: %d\n",number1, number2, resultado);
}

void restar(){
  int number1, number2, resultado=0;
  printf("Ingresa 2 n[umeros para restar:\n");
  scanf("%d %d",&number1, &number2); getchar();
  resultado = number1 - number2;
  printf("La resta de %d y %d es: %d\n",number1, number2, resultado);
}

void dividir(){
  float number1, number2, resultado=0;
  printf("Ingrese 2 n[umeros para dividir:\n");
  scanf("%f %f",&number1, &number2); getchar();

  resultado = number1 / number2;
  printf("La divisi[on entre %.2f y %.2f es: %.2f",number1, number2, resultado);
}

void multiplicar(){
  int number1, number2, resultado=0;
  printf("Ingreses 2 n[umeros para multiplicar:\n");
  scanf("%d %d",&number1, &number2); getchar();

  resultado = number1 * number2;
  printf("La multiplicaci[on de %d y %d es: %d\n",number1, number2, resultado);
}
