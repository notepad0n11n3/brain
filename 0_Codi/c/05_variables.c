/*
 *  Variables
 */

#include <stdio.h>

//  short in === short
// short int < int < long int
int main()
{
  char C = 'y';  // tamano de 1 byte 0...255    char  ]o caracter, es alfanumerico
  int a = 20;  // 2 bytes  -32768... 32767
  short e = -1; // 2 bytes  -128...127
  unsigned int u = 25; // 2 bytes  0..65535
  long l = 5932; //4bytes  -2147483648...2147483647

  float f = 72.534; 
  double d = 12323.887658; // 8bytes  tambi[en es un n[umero flotante/numeroReal

  printf("%c \n",C);  // %c  espera un char

  printf("%i \n",a);
  printf("%i \n",e);
  printf("%i \n",u);

  printf("%li \n",l);

  printf("%.2f \n",f); // %f espera un flotante, %.2f  dos decimales        4bytes
  printf("%.2lf\n",d);  // %f tambi[en sive.   %.2ls

  return 0; // termina el programa
}
