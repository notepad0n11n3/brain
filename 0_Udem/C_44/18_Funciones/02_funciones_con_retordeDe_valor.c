#include <stdio.h>

int funcionSumar();

int resultado=0, user_number1, user_number2;

int main(){

  printf("Ingresa 2 n[umeros para sumar:\n");
  scanf("%d %d",&user_number1,&user_number2); getchar();

  resultado = funcionSumar(user_number1,user_number2);

  printf("El resultado de la suma de %d y %d es: %d\n",user_number1,user_number2,resultado);


  printf("resultado en una linea => %d\n", funcionSumar(user_number1,user_number2) );

  return 0;
}

int funcionSumar(int num1, int num2){
  int variableLocal_resutlado=0;

  variableLocal_resutlado = num1 + num2;

  return variableLocal_resutlado;
}
