#include <stdio.h>

int main(){

      char            1 byte    -128  to  127
      unsigned char   1 byte      0   to  255

  (A) Valores enteros:

      short             2 bytes   -32,768  to 32,767
      unsigned short    2 bytes   0  to  65,535


      int               4 bytes   -2,147,483,648  to  2,147,483,647
      unsigned int      4 bytes   0  to  4,294,967,295

      long              8 bytes   -9223372036854775808 to 9223372036854775807
      unsigned long               0 to 18446744073709551615

  (B) De punto flotante:       en decimal NO existen variables de tipo unsigned <<==

      float           4bytes  2.2E-38 to 3.4E+38               6 decimal places    6 digitos despues del punto
      double          8bytes  2.3E-308 to 1.7E+308             15 decimal places   
      long double     10 bytes  3.4E-4932 to 1.1E+4932         19 decimal places



  return 0;
}
