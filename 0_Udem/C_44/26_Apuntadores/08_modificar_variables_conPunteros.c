#include <stdio.h>

int main(){

  int w=10, x=20, y=30, z=40, r1, r2, r3;
  int *p1, *p2, *p3, *p4;

  p1 = &w;
  p2 = &x;
  p3 = &y;

  printf("#=> %d\n",w);      // MODIFICAMOS VARIABLE POR MEDIO DE PUNTEROS
  p4 = p1;
  *p4 = 20;
  printf("##=> %d\n",w);

  r1 = *p1 + *p2;
  r2 = *p3 * *p4;
  r3 = *p2 + *p3;

  printf("Los Resultados son: %d, %d y %d", r1,r2,r3);
}
