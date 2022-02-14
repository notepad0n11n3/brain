#include <stdio.h>
#include <stdlib.h>

// pide un n[umero y se detiene si el n[umero es 0, muestra la suma de todos los n[umeros anteriores y el promeido
int main(){
  int suma=0,contador=0,numero=-1;  

  while(numero != 0){
    printf("Introduce un n[umero:");
    scanf("%d",&numero);
    contador++;
    suma += numero; // suma = suma + numero;
  }
  float promedio=suma/contador;
  printf("La suma de todos los n[umeros es: %d y el promedio es: %.2f",suma, promedio);

  return 0;
}
