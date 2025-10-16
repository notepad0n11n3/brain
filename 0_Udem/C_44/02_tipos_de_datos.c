#include <stdio.h>

#include <stdbool.h>  // para usar booleanos    true/false

int main(){
  int a = 1; printf("Entero => %i\n",a); // %i === %d      2 bytes Rango desde -32768 -> 32767
  char b = 'z'; printf("Caracter => %c\n",b);  // 1 byte Rango desde 0 -> 255
  float c = 1.654321; printf("Flotante => %f\n",c); // 4bytes
  double d = 144444444.555555555555555555555; printf("Flotante maGrande lf (longFloat)=> %lf\n",d);// 8bytes
  short v = 2; printf("Short enteroPeque~o=> %i\n",v); // 2 bytes  Rango desde -128 -> 127
  long e = 12.3; printf("long li => %li",e); // 4 bytes

  unsigned int f = 123; printf("unsignedInt => %i\n",f);   // SOLO POSITIVO  2bytes Rango desde  0 -> 65535
  //long double 
  //bool

  return 0;
}
