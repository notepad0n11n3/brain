#include <stdio.h>
      /// incompleto    INCOMPLETO

struct Direccion{
  char* calle;
  char* barrio;
  int nro;
};


struct Persona{
  char* nombre;
  int edad;
  struct Direccion dir;
};


struct Libro{
  char* nombre;
  int anio;
  struct Persona autores[10];
};


int main(int argc, char *argv[]){
  struct Libro libros[20];

  int cantidad_libros, numero_autores;

  fprintf(stdout, "\n\t Ingrese cantidad de libros: "); scanf("%d", &cantidad_libros);
  for(int i=0; i<cantidad_libros; i++){
    fprintf(stdout, "\n\tIngrese nombre del libro: "); libros[i].nombre = gets();
    fprintf(stdout, "\n\tIngrese el a~o de publicacion: "); scanf("%d", &libros[i].anio);
    fprintf(stdout, "\n\tIngrese cantidad de autores: "); scanf("%d", &numero_autores);

    for(int j=0; j<numero_autores; j++){
      fprintf(stdout, "\n\t Ingrese el nombre del autor: ");
    }
  }
  return 0;
}

