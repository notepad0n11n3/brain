/*FUNCIONES MATEM[ATICAS:

ceil(x) -> Redondea al entero mayor m[as cercano
fabs(x) -> Devuelve el valor absoluto de x
floor(x) -> Redondea al entero menos m[as cercano
sqrt(x) ->  Saca la raiz cuadrada de x
fmod(x,y) -> Calcula el resto de la division de x/y
pow(x,y) -> Calcula x elevado a la potencia y             */
#include <stdio.h>
#include <math.h>
                            // ::: gcc 03_funcionesMAT.c -lm
void funcionMateDes();
void funcionMateDosDigitos();

int main(){
//funcionMateDes();
  funcionMateDosDigitos();
  return 0;
}

void funcionMateDes(){
  float user_number, resultado=0;
  printf("Ingrese un n[umero:\n");
  scanf("%f",&user_number); getchar();

//resultado = ceil(user_number);
//resultado = fabs(user_number);
//resultado = floor(user_number);
  resultado = sqrt(user_number);
  printf("=> %.2f\n",resultado);
}

void funcionMateDosDigitos(){
  float user_number1, user_number2, resultado=0; printf("Ingrese 2 n[umeros:\n"); scanf("%f %f",&user_number1,&user_number2); getchar();

  resultado = fmod(user_number1,user_number2); // es el modulo num1%num2 pero en funcion :u
//resultado = pow(user_number1,user_number2);
  printf(":::> %.2f\n",resultado);
}
