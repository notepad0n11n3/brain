// memoria dinamica: es un tipo de memoria que se reserba en tiempo de ejecuci[on, puede variar al momento de ejecutarse

#include <stdio.h>
#include <stdlib.h> // malloc esta ac[a

int main()
{
  int n = 10;
  char * p;
  p = malloc(n*sizeof(char));   // malloc nos permite reservar memoria para los caracteres que nosotros vayamos a ingresar
   //como queremos reserbar memoria para una cadena de caracteres usaremos char
   // SEIZEOF devuelve el tamano el bytes que tiene una variable
   // malloc va a almacenar el tamano de una variable en especifico

    if(NULL == p) // comprobamos si p no tiene nada, se reserbo 10 espacio para nuestra variable p. 
    {
      printf("Error al asignar memoria \n");
    }else{
      printf("Se asigno memoria\n");
    }

  return 0;
}
