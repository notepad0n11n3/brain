#include <stdio.h>

int main(){
  float gradosCelcius,gradosFahrenheit;
  printf("Escribe la cantidad de grados Celsius: \n");
  scanf("%f",&gradosCelcius);

  gradosFahrenheit = (gradosCelcius * 1.8) + 32;

  printf("=> %.2f grados Celcius son '%.2f' grados Fahrenheit\n",gradosCelcius, gradosFahrenheit);

  return 0;
}
