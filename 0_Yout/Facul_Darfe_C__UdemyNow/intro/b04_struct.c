#include <stdio.h>


struct Persona{
  char *nombre;
  int edad;
  float peso;
};

    // se puede iniciar struct de las 2 formas :)
struct{
  char *nombre;
  int edad;
  float peso;
}p1, p2;



int main(int argc, char *argv[]){

  struct Persona p1, p2;

  p1.nombre = "Juan";
  fprintf(stdout, "\n\t %s Ingrese la edad:  ", p1.nombre);
  scanf("%d", &p1.edad); p1.peso = 80;

  p2.nombre = "Marcela";
  fprintf(stdout, "\n\t %s Ingrese la edad:  ", p2.nombre);
  scanf("%d", &p2.edad); p2.peso = 60.5;


  fprintf(stdout, "\n\t\tNombre: %s, Edad: %d, Peso: %.2f.\n", p1.nombre, p1.edad, p1.peso);
  fprintf(stdout, "\n\t\tNombre: %s, Edad: %d, Peso: %.2f.\n", p2.nombre, p2.edad, p2.peso);


  return 0;
}
