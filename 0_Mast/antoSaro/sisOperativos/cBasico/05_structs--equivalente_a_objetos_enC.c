#include <stdio.h>
#include <stdlib.h>
/* en C no existen los OBJETOS, solo los structs, son un tipo de coleccion de datos concretos
 */

struct PuntoDes {
// typedef struct{  **
  double x;
  double y;
};              //  <<<-------     ;     ;    ;
//} Punto;          **

int main() {
//PuntoDes punto = {0.5, 5.9};   **

  struct PuntoDes punto = {0.5, 5.9};
//struct PuntoDes punto = {.y = 5.9, .x = 0.5};  declarandoValorDesorden

  printf("x: %f, y: %f \n", punto.x, punto.y);


  // -------------------- inicializando en el Heap --------------------
  // no esta en nuestra zona de memoria, esta en el Heap  (malloc)
  
  struct PuntoDes *puntoN = malloc(sizeof(struct PuntoDes)); //puntero a un struct que esta en el Heap

  puntoN->x = 0.5;
  puntoN->y = 5.9;
  
  printf("x: %f, y: %f \n", puntoN->x, puntoN->y);

  free(puntoN);
}
