
#include <stdio.h>

int main()
{
  int casos;
  printf("\tIngresa un n]umero: \n");
  scanf("%i", &casos); 

  switch(casos)
  {
    case 1:
      printf("La opcion elegida es 1");
      break;
    case 2:
      printf("La opcion elegida es 2");
      break;
    case 3:
      printf("La opcion elegida es 3");
      break;
    case 4:
      printf("La opcion elegida es 4");
      break;
    case 5:
      printf("La opcion elegida es 5");
      break;
    default:
      printf("Opcion incorrecta... :(");
      break;
  }

}
