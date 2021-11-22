
/*
 *  Estructuras
 *  Es una coleccion de 1 [o m[as tipos de elementos denominados miembros, estos miembros pueden ser de un tipo de dato diferente
 */

#include <stdio.h>

struct perro
{
  char nombre[30];  // 30 es la cantidad max de caracteres para el nombre
  int edadMeses;
  float peso;
// }perro1={"Chikorita",10,3.50};
}
perro1={"chikorita",10,3.50},
perro2={"Arduino",4,2.30};

int main()
{
  printf("El peso de: %s es %.2f Kg y tiene %i meses\n", perro1.nombre, perro1.peso, perro1.edadMeses);
  printf("El peso de: %s es %.2f Kg y tiene %i meses\n", perro2.nombre, perro2.peso, perro2.edadMeses);
  return 0;
}
