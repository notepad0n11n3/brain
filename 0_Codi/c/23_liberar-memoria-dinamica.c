
#include <stdio.h>
#include <stdlib.h> // malloc here
#include <string.h>

#define length 2

int size;

struct dog
{
  char name[20];
  char *p_name;
}dogs[length];

int main()
{
  for (int i = 0; i < length; ++i)
  {
    printf("Ingrese el nombre del perro\n");
    fgets(dogs[i].name, 20, stdin); //stdin nos permite optener lo ingresado por el teclado
    size = strlen(dogs[i].name);

    printf("%i\n",size);
    dogs[i].p_name = malloc(size * sizeof(char) );

    if (NULL == dogs[i].p_name)
    {
      printf("Error al asignar Memoria");
    }else{
      strcpy(dogs[i].p_name,dogs[i].name); 
    }
  }
  for (int i = 0; i < length; ++i)
  {
    printf("El nombre del perro es %s\n", dogs[i].p_name);
  }
  
  return 0;
}
