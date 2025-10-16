
 //operador unario sizeof: para determinar el tamano en bites de un arreglo o cualquier otro tipo de dato.

/*
#include <stdio.h>

int main()
{
  float array[20];
  printf("El n[umero de bytes en el arreglo es: %lu \n", sizeof(array) );

  return 0;
}
*/

//********************
//

#include <stdio.h>

size_t getsize(float *ptr);
int main()
{
  float array[20];
  printf("El n[umero de bytes en el arreglo es: %lu \n", sizeof(array) );
  printf("El n[umero de bytes devueltos por getsize es: %lu \n",getsize(array) );
  return 0;
}

size_t getsize(float *ptr)
{
  return sizeof(ptr);
}
