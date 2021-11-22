#include <stdio.h>

/* cuenta la cantidad de espacio, si existe muchos espacios juntos solo se contara como un espaico */
main()
{
  int c, last_char_printed, current_char;

  while ( (c = getchar()) != EOF ){
    if( current_char != ' ' || last_char_printed != current_char ){
      putchar(current_char);
    }
    putchar(current_char);
    last_char_printed = current_char
  }
}
