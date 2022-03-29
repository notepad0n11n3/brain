#include <stdio.h>
#include <string.h>

struct persona{  // El struct tambien puede ir por fuera de la funcion
  char nombre[20];
  int edad;
}persona3={"nombrePrueba3",100},persona4;
// Formas de declarar struct
//}persona1,persona2,personan;
//}persona1={"manolo",88},persona2={"nee",96};

int main(){
  struct persona persona1,persona2,personan;

//persona1.nombre={"manolo"};
  strcpy(persona1.nombre, "manolo");
  persona1.edad=88;

//persona2.nombre={"nee"};  <== no funciona
  strcpy(persona2.nombre, "nee");
  persona2.edad=96;

                      // si, el struct puede estar por dentroFuera de la funcPrincipal
  printf("\n Su nombre es %s y tiene %d a~os.",persona3.nombre,persona3.edad);
  printf("\n Su nombre es %s y tiene %d a~os.",persona1.nombre, persona1.edad);
  printf("\n Su nombre es %s y tiene %d a~os.",persona2.nombre, persona2.edad);
  return 0;
}
