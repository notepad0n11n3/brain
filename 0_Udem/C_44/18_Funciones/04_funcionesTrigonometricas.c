/*FUNCIONES TRIGONOMETRICAS

acos(x) -> Calcula el Arco Coseno de x
asin(x) -> Calcula el Arco Seno de x
atan(x) -> Calcula el Arco Tangente de x
cos(x) -> Calcula el Coseno de x
sin(x) -> Calcula el Seno de x
tan(x) -> Calcula la Tangente de x          */

#include <stdio.h>
#include <math.h>
                      // ::: gcc 04_funcionesTrigo*.c -lm
void miFuncion();
int main(){

  miFuncion();
  return 0;
}

void miFuncion(){
  float user_number, resultado=0;
  printf("Ingrese un n[umero:\n");
  scanf("%f",&user_number); getchar();

  resultado = acos(user_number);
  printf("El resultado es: %.2f\n",resultado);
}
