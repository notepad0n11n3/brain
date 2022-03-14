#include <stdio.h>

void binarioPuro(int arreglo1[]); void puntoFijo(int arreglo1[]); void complementoA2(int arreglo1[]);

int main(){
  int arreglo1[10], user_option;

  printf("\t\nEste programa hace conversiones de binario a tres diferentes tipos de codificaci[on \n");
  printf("Primero llena el arreglo de 10 elemento\n\tSOLO USA CERO Y UNO (0 1)\n");

  // Llenar el arreglo
  for(int i=0; i<10; i++){
    printf("\nEscribe el elemento [%i] del arreglo: ",i);
    scanf("%d",&arreglo1[i]); getchar();
    if(arreglo1[i]!=1 && arreglo1[i]!=0){
      printf("\n\t\t Error... solo es permitido 0 y 1. :(");
      i--;
    }
  }

  // Imprime el arreglo
  printf("\nEl arreglo queda de esta manera\n"); printf("\t[");
  for(int i=0; i<10; i++){
    if(i==9){
      printf("%d",arreglo1[i]);
      break;
    }
    printf("%d ",arreglo1[i]);
  } printf("]\n");

  printf("\nEscoge la opci[on\n 1) Binario Puro\n 2) Punto Fijo (6 bit entero y 4 bit decimal)\n 3) Complemento a 2\n");
  scanf("%d",&user_option); getchar();

  switch(user_option){
    case 1:
      printf("Seleccionaste binario puro\n");
      binarioPuro(arreglo1);
      break;
    case 2:
      printf("Seleccionaste Punto Fijo\n");
      puntoFijo(arreglo1);
      break;
    case 3:
      printf("Seleccionaste Complemento a 2\n");
      break;
    default: printf("\n\tOpci[on incorrecta..\n"); break;
  }

  return 0;
}

void binarioPuro(int arreglo1[]){
  int valor=512, suma=0;  // 512 es de 2 a la 9, el array tiene 10 elementos del 0-9

  for(int i=0; i<10; i++){
    if(arreglo1[i] == 1){
      suma += valor;
    }
    valor /= 2;
  }

  printf("El valor en decimal es: %i\n",suma);
}

void puntoFijo(int arreglo1[]){
  int suma=0, valor=32;  // valor = 32 + 16 + 8 + 4 + 2 + 1    111111==6bits
  float sumaDecimal=0, valorDecimal=0.5;

  // Parte Entera
  for(int i=0; i<6; i++){
    if(arreglo1[i] == 1){
      suma += valor;
    }
    valor /= 2;
  }

  // Parte Decimal
  for(int i=6; i<10; i++){
    if(arreglo1[i] == 1){
      sumaDecimal += valorDecimal;
    }
    valorDecimal /= 2;
  }
  printf("El valor del n[umero en punto fijo es %.4f\n",suma+sumaDecimal);
}

void complementoA2(int arreglo1[]){
  int posicion;

  for(int posicion=0; posicion<10; posicion++){
    if(arreglo1[posicion] == 1){
      arreglo1[posicion] = 0;
    }else {
      arreglo1[posicion] = 1;
    }
  }
  
  posicion=9;
  while(arreglo1[posicion] == 1){
    arreglo1[posicion] = 0;
    posicion--;

    if(arreglo1[posicion] == 0){
      arreglo1[posicion] = 1; break;
    }
  }


  if(arreglo1[posicion] == 0){
    arreglo1[posicion] = 1;
  }

  //Imprimir arreglo
  printf("\n\n\t[");
  for(int i=0; i<10; i++){
    if(i==9){
      printf("%d",arreglo1[i]); break;
    }
    printf("%d ",arreglo1[i]);
  }; printf("]\n");
}
