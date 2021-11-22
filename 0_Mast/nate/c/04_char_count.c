#include <stdio.h>

/*  archivoC.exe < archivo  */
main()
{
  Long nc; 

  nc = 0;
  while(getchar() != EOF)
    ++nc;
  printf("%ld \n", nc);  /* Esto esta por fuera del while, print la cantidad de caracteres*/

  /* con for */
  for (nc = 0; getchar() != EOF; ++nc)
    ;
  printf("%ld \n", nc);

}
