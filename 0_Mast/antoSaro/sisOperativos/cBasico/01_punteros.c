#include <stdio.h>
          //  Libreria del sistema va entre <>    <stdio.h>
          //  Librefia PROPIA va entre ""        <gorox89p>

int main() { 
  int a = 5;

  int *pointerGoro_a= &a;    //  &  sirve para sacar la direcci[on en memoria de una variable
                            // sin & dar[a error, ya no ser[ia un puntero, seria una declaraci[on de variableInt....!!! 
  int *sauron= &a;
  int *another_pointer = pointerGoro_a;

  printf("1 Valor de a con &      : %p \n", &a);
  printf("2 Valor del puntero     : %p \n", pointerGoro_a);     // p   puntero
  printf("3 Valor donde apunta el puntero: %i \n", *pointerGoro_a); // i int

  printf("4 Valor de otro puntero: %p \n", another_pointer); // i int
  printf("5 Valor de puntero tras puntero: %i \n", *another_pointer);
        
            ///   con  *nombrePunteroHere    vamos al valor de la direcci[on de memoria, sin * devuelve la direci[on de memoria

  printf("Hello direccion memoria...:  %i \n", *sauron);  //CON * VALOR DE DIRECCION DE MEMORIA
  printf("Hello again puntero...:: %p \n", sauron);   //SIN * DIRECCION DE MEMORIA

  *pointerGoro_a=69; // Reasignando valor de variable atravez de puntero

  printf("Reasignando valor de variable atravez de puntero: %i \n", *pointerGoro_a);

  return 0;   // todo a salido bien
}
