#include <stdio.h>

float mediAri(float des1, float des2);

int main(){
  float user_number1, user_number2;

  printf("Ingrese 2 n[umeros: \n");
  scanf("%f %f",&user_number1, &user_number2); getchar();

  printf("La media aritmetica de %.2f y %.2f es: %.2f\n", user_number1, user_number2, mediAri(user_number1, user_number2) );
  return 0;
}

float mediAri(float des1, float des2){
  float resultado = (des1 + des2)/2; return resultado;
}
