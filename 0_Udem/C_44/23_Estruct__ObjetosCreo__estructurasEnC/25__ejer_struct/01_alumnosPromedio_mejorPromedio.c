#include <stdio.h>
#include <string.h>

struct alumno{
  char nombre[44];
  int edad;
  float promedio;
}alumno[3];

int main(void){
  float mejor_calificacion = 0.0;

  for(int i=0; i<3; i++){
    printf("\nIngrese el nombre %d: ", i+1);
    fgets(alumno[i].nombre, 44, stdin); strtok(alumno[i].nombre, "\n");

    printf("\nIngrese la edad %d: ", i+1);
    scanf("%d", &alumno[i].edad); getchar();

    printf("\nIngrese el promedio %d: ", i+1);
    scanf("%f", &alumno[i].promedio); getchar();
  }

  int posicion;
  for(int i=0; i<3; i++){
    if( alumno[i].promedio > mejor_calificacion ){
      mejor_calificacion = alumno[i].promedio;
      posicion=i;
    }
  }

  printf("\n\tEl alumno con mejor calificaion es: \n");
  printf("\t Nombre: %s\n\t Edad: %d\n\t Promedio: %.2f", alumno[posicion].nombre, alumno[posicion].edad, alumno[posicion].promedio);
  return 0;
}
