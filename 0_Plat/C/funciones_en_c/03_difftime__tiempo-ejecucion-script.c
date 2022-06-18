#include <stdio.h>
#include <time.h>

time_t begin, end;

int main(void){

  long i;
  begin = time(NULL);             // time(NULL)   retorna el tiempo actual del sistema

  for(int i=0; i < 150000000; i++){
  }

  end = time(NULL);         // volvemos a obtener el tiempo actual y comparamos con difftime() 

  printf("El tiempo que duro nuestro for es: %f \n", difftime(end, begin) );
  
  return 0;
}
