#include <stdio.h>
#include <string.h>

struct molde{
  char nombre_here[40];
  int edad;
};

int main(){
  struct molde persona[3];

  for(int i=0; i<3; i++){
    printf("\nIngrese el nombre para la %d persona: ",i);
    fgets(persona[i].nombre_here, 40, stdin); strtok(persona[i].nombre_here, "\n");

    printf("\nIngrese la edad para %d persona: ",i);
    scanf("%d",&persona[i].edad); getchar();
  }

  for(int i=0; i<3; i++){
    printf("\n El nombre de la persona %d es %s\n",i,persona[i].nombre_here);
  }
  return 0;
}
