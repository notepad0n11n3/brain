#include <stdio.h>

/* cuenta las lineas de entrada */

main()
{
  int c, nl;

  nl = 0;

  while ( (c = getchar() ) != EOF ){
    if (c == ''n'){   /* conprueba si el caracter en c es igual a un salto de linea*/
      ++nl;
    }
  }
  printf("%d \n", nl);
}
