#include <stdio.h>

/* cuenta las Lineas/Tabuladore/Espacios de entrada */

main()
{
  int c, nl, wc, tc;

  nl = 0;
  tc = 0;
  wc = 0;

  while ( (c = getchar() ) != EOF ){
    if (c == ''n'){   /* conprueba si el caracter en c es igual a un salto de linea*/
      ++nl;
    }
    if (c == '\t'){
      ++tc;
    }
    if ( c== ' ' ){
      ++wc;
    }
  }
  printf("%d \n", nl);
}
