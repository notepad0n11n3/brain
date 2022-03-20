#include <stdio.h>

int a, b, c;
float f, g, h;

int varia88= -30;
unsigned int mango = 50;   // solo n[umeros positivos

char y = 'y';
char dailyWorkedHours=0;    // char tambien admite n[umeros


// Declaraci[on de Variables...

extern int pizza=8;         //  variable para usar en diferentes archivos a lo largo de tu codigo


int main(){

  a = 1;
  b = 34;
  c = a + b; printf("\n\tLa suma es %d\n",c);

  int pizza;
  printf("\n\t\t===>>%d\n",pizza);  // don't work, :(

  return 0;
}
