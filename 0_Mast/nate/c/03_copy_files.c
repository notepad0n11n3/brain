#include <stdio.h>


/*
 * Copia un archivo caracter a caracter
 *
 *  ::: ./archivo.c < textAcopiar.txt > testoCopiado.txt
 *  ::: ./archivo.c < textAcopiar.txt  # solo mostrara en pantalla el testo de *.txt
 *  ::: ./arhcivo.c  # se queda en escucha, ingresa algo despues <CR> y dara un print
 */ 

main()
{
  int c;

  c = getchar(); /* Coge un caracter getchar()*/
  while (c != EOF)  /* constante EOF=== end of file, por defecto es -1*/
  {
    putchar(c); /* muestra un caracter por la salida standard, consola*/
    c = getchar();
  }
}
