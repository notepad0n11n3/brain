
#include <stdio.h>

struct perro
{
  char nombre[30]; // 30 es la cantidad max de caracteres para el nombre
  int edadMeses;
  float peso;
}perros[3];

int main()
{

  for ( int i = 0; i < 3; ++i)
  {
    printf("%i Ingresa el nombre del perro\n", i+1);
    scanf("%s",&perros[i].nombre);

    printf("%i Ingresa la edad del perro:\n", i+1);
    scanf("%i",&perros[i].edadMeses);

    printf("%i Ingrese el peso del perro\n\n", i+1);
    scanf("%f",&perros[i].peso);
  }

  for (int i = 0; i < 3; ++i)
  {
    printf("%i El nombre del perro es: %s \n", i+1, perros[i].nombre );
    printf("%i La edad del perro es: %i \n", i+1, perros[i].edadMeses );
    printf("%i El peso del perro es: %.2f \n\n", i+1, perros[i].peso );
  }
  return 0;
}
