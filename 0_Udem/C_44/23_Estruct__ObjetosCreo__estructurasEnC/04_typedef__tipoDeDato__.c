#include <stdio.h>

// struct nameHere{
// }struct[10];     ====     }struct1, struct2, struct3, ..., struct9

int main(){

  // Definimos un nuevo tipo llamado "MiTipoDeDato"
  // Esto solo es otra manera de declarar un entero
  typedef int MiTipoDeDato;

  // Ahora podemos crear variables del tipo "MiTipoDeDato"
  MiTipoDeDato variable1;

  // Pero tambi[en podemos seguir usando int
  int variable2;

  printf("\nEscribe 2 enteros: ");
  scanf("%d %i",&variable1, &variable2); getchar();

  printf("\nNumeros digitados: %i - %d",variable1, variable2);

  
  typedef float nuevoTipoDato;

  nuevoTipoDato flotante_usuario1;
  float flotante_usuario2;

  printf("\nIngrese 2 numeros flotantes: ");
  scanf("%f %f",&flotante_usuario1, &flotante_usuario2); getchar();

  printf("\nLos n[umeros flotantes ingresados son: %.2f - %.2f",flotante_usuario1, flotante_usuario2);

  return 0;
}
