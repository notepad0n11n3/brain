#include <stdio.h>

/*
 **  Puntero NULL:  Es un puntero que no apunta a ninguna direcci[on de memoria v[alida. Es recomendable inicializar una variable puntero en NULL para evitar problemas.
 *
 *
 **  Puntero gen[erico: Hay ocasiones en las que no sabemso a que tipo de dato va a apuntar una variable puntero determinado. Para eso podemos declarar uan variable como puntero gen[erico.
 */

int main(int argc, char *argv[]){

  int *puntero_BuenasPracticas = NULL;  // es una buena pr[actica iniciar un puntero con NULL, para evitar basura de memoria

  // puntero GENERICO

  void *puntero_generico; //puede apuntar a cualquier tipo de variable int, char, float, etc...

  return 0;
}
