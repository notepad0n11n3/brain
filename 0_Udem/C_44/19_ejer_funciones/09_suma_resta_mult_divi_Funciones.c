#include <stdio.h>
#include <stdlib.h>

int sumar(int one, int two); int restar(int one, int two); float division(float one, float two); int multiplicar(int one, int two);
int user_option, number1, number2;

int main(){
  do{
    printf("\n\t=> 1) Sumar. 2) Restar. 3) Multiplicar. 4) Dividir.  5) SALIR.\n");
    scanf("%d",&user_option); getchar();
    printf("Ingrese 2 n[umeros:\n");
    scanf("%d %d", &number1, &number2);
    switch(user_option){
      case 1: printf("La suma de %d y %d es: %d\n",number1,number2, sumar(number1,number2) ); break;
      case 2: printf("La resta de %d y %d es: %d\n",number1,number2, restar(number1,number2) ); break;
      case 3: printf("La multiplicaci[on de %d y %d es: %d\n",number1,number2, multiplicar(number1,number2)); break;
      case 4: printf("La division de %d y %d es: %.2f\n",number1,number2, division(number1,number2) ); break;
      case 5: system("clear"); printf("\n\n\t\t Saliendo...\n"); break;
      default: printf("\n\n\n\t\t\t Error... Opci[on incorrecta.\n"); break;
    }
  }while(user_option != 5);
  return 0;
}

int sumar(int num1, int num2){
  int resultado=num1+num2; return resultado;
}

int restar(int num1, int num2){
  int resultado=num1-num2; return resultado;
}

int multiplicar(int num1, int num2){
  int resultado=num1*num2; return resultado;
}

float division(float num1, float num2){
  float resultado=num1/num2; return resultado;
}
