#include <stdio.h>

/* CONSTANTES SINBOLICAS, ASIGNAR UN NOMBRE A UN NUMERO
 *    no son variables, no ocupan espacio en memoria, el compilador va a ignorar y reemplazar 
 *    las constantes simbolicas por el valor real, es mas para ayuda visual del programador*/
#define LOWER 0
#define UPPER 300
#define STOP 20
main()
{
  int fahr;

  /*for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STOP) */
  for (fahr = 0; fahr <= 300; fahr = fahr + 20)
  {
    printf("%3d \t %6.1f \n", fahr, (5.0 / 9.0) * (fahr - 32));
  }
}
