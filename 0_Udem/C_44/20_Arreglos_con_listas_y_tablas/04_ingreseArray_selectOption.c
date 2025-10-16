#include <stdio.h>
#include <stdlib.h>
            //   void mi_funcion(int mango[], int 10);
            //   mi_funcion(array_here, size_array);         // por default creo que se pasa por referencia(los cambios afectaran al arrayOriginal)

void optionUser(); void array_data(); int sumar(); int multiplicar(); int suma_multiplos3(); void todo_por_3();

int litle_array[10];

int main(){

  array_data();


  optionUser();

  return 0;
}

void optionUser(){
  int optionFunction=0;
  int whileDes=0;
  while(whileDes==0){
    printf("\n 1) Modificar el continedo del array\n 2) Sumar el contenido del array\n 3) Multiplicar el contenido del array\n 4) Sumar SOLO los elementos multiplos entre 3\n 5) Multiplicar por 3 cada elemento del arreglo\n 6) Salir\n");
    scanf("%d",&optionFunction); getchar();
    switch(optionFunction){
      case 1:
        array_data();
        break;
      case 2:
        sumar();
        break;
      case 3:
        multiplicar();
        break;
      case 4:
        suma_multiplos3();
        break;
      case 5:
        todo_por_3();
        break;
      case 6:
        whileDes=1; system("clear");printf("\n\t Saliendo...\n");
        break;
      default:
        printf("\n\t ERROR... opci[on inv[alida. :(\n");
        break;
    }
  }
}

void array_data(){
  printf("\t\tIngrese los n[umeros para el array:\n");

  for(int i=0; i<=9; i++){
    printf("Ingrese el valor de la posici[on [%i]: ",i);
    scanf("%d",&litle_array[i]); getchar();
  }
  system("clear");

  printf("\tEl Array tiene los valores de={");
  for(int i=0; i<=9; i++){
    if(i==9){
      printf("%i",litle_array[i]);
      break;
    }
    printf("%i ",litle_array[i]);
  }
  printf("}");
}

int sumar(){
  int sumaFunction=0;
  for(int i=0; i<=9; i++){
    sumaFunction += litle_array[i]; 
  }
  system("clear");
  printf("\n\t La Suma total del contenido del array es: %d\n",sumaFunction);
}

int multiplicar(){
  int multiFunction=1;
  for(int i=0; i<=9; i++){
    multiFunction *= litle_array[i];
  }
  printf("\n\t La multiplicaci[on del contenido del array es: %d\n",multiFunction);
}

int suma_multiplos3(){
  int resultado=0;
  for(int i=0; i<=9; i++){
    if(litle_array[i]%3==0){
      resultado += litle_array[i];
    }
  }
  printf("\n La Suma de los Elementos Multiplos de 3 es: %d\n",resultado);
}

void todo_por_3(){
  for(int i=0; i<=9; i++){
    printf("%d x 3 = %d\n",litle_array[i],litle_array[i]*3);
  }
}
