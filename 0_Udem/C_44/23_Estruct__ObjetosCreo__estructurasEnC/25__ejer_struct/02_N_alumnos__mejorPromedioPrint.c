#include <stdio.h>
#include <string.h>

struct promedio{
  float nota1;
  float nota2;
  float nota3;
};

struct alumno{
  char nombre[20];
  char sexo[20];
  int edad;
  struct promedio prom;
}alumnos[100];            // Despu[es juego con asignaci[on dinamica de memoria :)

int main(void){
  int promedio_Mayor = 0, total_Alumnos, alumno_promedio_mayor;
  float promedios_Alumnos[100];

  printf("\n Escribe el total de Alumnos: ");
  scanf("%d",&total_Alumnos); getchar();

  for(int i=0; i<total_Alumnos; i++){
    printf("\nIngrese el nombre %d: ", i+1);
    fgets(alumnos[i].nombre,20,stdin); strtok(alumnos[i].nombre, "\n");

    printf("\nIngrese el sexo %d: ", i);
    fgets(alumnos[i].sexo, 20, stdin); strtok(alumnos[i].sexo, "\n");

    printf("\nIngrese la edad %d: ", i);
    scanf("%d", &alumnos[i].edad); getchar();

    printf("\nIngrese la nota 1: ");
    scanf("%f", &alumnos[i].prom.nota1); getchar();

    printf("\nIngrese la nota 2: ");
    scanf("%f", &alumnos[i].prom.nota2); getchar();

    printf("\nIngrese la nota 3: ");
    scanf("%f", &alumnos[i].prom.nota3); getchar();

    promedios_Alumnos[i] = (alumnos[i].prom.nota1 + alumnos[i].prom.nota2 + alumnos[i].prom.nota3)/3;

    if( promedios_Alumnos[i] > promedio_Mayor ){
      promedio_Mayor = promedios_Alumnos[i];
      alumno_promedio_mayor = i;
    }
  }

  printf("\nEl alumno con el mayor promedio es: \n");
  printf("\n\tNombre: %s", alumnos[alumno_promedio_mayor].nombre);
  printf("\n\tSexo: %s", alumnos[alumno_promedio_mayor].sexo);
  printf("\n\tEdad: %d", alumnos[alumno_promedio_mayor].edad);
  printf("\n\tPromedio: %.2f", promedios_Alumnos[alumno_promedio_mayor]);
  return 0;
}
