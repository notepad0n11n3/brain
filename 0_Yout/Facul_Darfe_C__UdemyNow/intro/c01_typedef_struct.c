#include <stdio.h>



typedef struct{
  float x, y;
} tPunto;



// sobreescribir el tipo de dato 'int' por tEntero... <3 <3 <3
typedef int tEntero;


#define MAX 40
typedef tPunto tMi_lista[MAX];

tEntero mi_funcion_sumarPuntos(tMi_lista lista, int N);

int main(int argc, char *argv[]){

  tPunto p;
  tEntero a=3, b=2;

  tMi_lista lista; // Esto es equivalente a hacer tPunto lista[MAX]

  fprintf(stdout, "\n\t Enteros: %d, %d\n", a, b);

  return 0;
}

tEntero mi_funcion_sumarPuntos(tMi_lista lista, int N){
  tPunto p;

  p.x =0; p.y=0;
  for(int i=0; i<N; i++){
    p.x += lista[i].x;
    p.x += lista[i].y;
  }
}
