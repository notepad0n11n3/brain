
#include <stdio.h>

#define length 2

struct owner
{
  char nombre[20]; // 20 es la cantidad de caracteres max para el nombre
  char direccion[30]; // 30 es la cantidad max de caracteres para la direcci[on
};
 
struct dog
{
  char nombre[20];  // 20 es la cantidad max de caracteres para el nombre
  int edadMeses;
  struct owner ownerDogDesu;
}dogs[length];


int main()
{
  for (int i = 0; i < length; ++i)
  {
    printf("Nombre del Perro\n");
    scanf("%s",&dogs[i].nombre);

    printf("Edad del perro\n");
    scanf("%i",&dogs[i].edadMeses);

    printf("Nombre del dueno");
    scanf("%s",&dogs[i].ownerDogDesu.nombre);

    printf("Direcci[on\n");
    scanf("%s",&dogs[i].ownerDogDesu.direccion);

    printf("\n");
  }

  for (int i = 0; i < length; ++i)
  {
    printf("El nombre del perro es: %s \n",dogs[i].nombre );
    printf("Edad en meses del perro: %i \n",dogs[i].edadMeses );
    printf("El nombre del duenho es: %s \n",dogs[i].ownerDogDesu.nombre );
    printf("La direcci[on del duenho es: %s \n",dogs[i].ownerDogDesu.direccion );
  }

  return 0;
}

