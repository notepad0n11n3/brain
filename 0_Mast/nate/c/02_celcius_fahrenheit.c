#include <stdio.h>
/* Imprimir una tabla de equivalencia entre Fahrenheit y Celcius , la tabla va de 20 en 20, desde 0 hasta 300*/


main()
{
  /* TIPAJE FUERTE, tipo de variable int, float, etc...  */
  float fahr, celcius;
  int lower, upper, step;

  lower=0;
  upper=300;
  step=20;

  fahr=lower;

  printf("        columna1 \t  columna2 \n");
  while (fahr <= upper)
  {
    celcius = 5 * (fahr-32) / 9;
    /*printf("%d\t%d\n", fahr, celcius); /*  \t=> tabulador  \n=> enter  %d=> espacioParaLasVariables fahr, celcius*/
    printf("\t%3.0f F \t\t%3.3f C \n", fahr, celcius);
    /* %3d     el 3 reserva 3 espacios para el resultado, el printf sera pegado a la derecha :)*/
    /* %3.3f  reserva 3 caracteres para la parte entera y deciaml  123.324 */
    /* %d para variables tipo int ---  %f  para variables tipo float*/
    fahr = fahr + step;
  }
}
