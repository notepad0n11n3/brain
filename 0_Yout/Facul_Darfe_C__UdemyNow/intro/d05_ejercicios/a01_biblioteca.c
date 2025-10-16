#include <stdio.h>            // INCOMPLETO INCOMPLETO INCOMPLETO
#include <string.h>
#include <stdlib.h>

#define TMAX 40

typedef char tCadena[TMAX];


typedef struct{
  long codigoLibro;    //codigo de cada libro
  tCadena nombre;
  int cantAutores;
  tCadena autores[TMAX];
  int cantPaginas;
  float precio;
}tLibro;

typedef tLibro tListaLibros[TMAX];


//      prototipos
int menu();
tLibro nuevoLibro();
void limpiarBuffer();
void scanString(tCadena s);
void insertarLibroOrdenado(tListaLibros libros, int *N, tLibro nuevo);
int busqBinaria(tListaLibros libros, int N, tCadena nombre);
void actualizarPrecioLibro(tLibro *libro);
void eliminarLibro(tListaLibros libros, int *N, int pos);
void mostrarLibro(tLibro libro);
void mostrarLibros(tListaLibros libros, int N);


int main(int argc, char *argv[]){

  int opc, N=0, pos;
  tListaLibros libros;
  tLibro libro;
  tCadena nombreLibro;

  opc = menu();
  while(opc != 0){
    system("clear");
    switch(opc){
      case 1:
        if(N < TMAX){
          fprintf(stdout, "----Insertar un nuevo libro----\n");
          libro = nuevoLibro();
          insertarLibroOrdenado(libros, &N, libro);
          fprintf(stdout, "\nEl libro se ha insertado exitosamente.\n");
        }else {
          fprintf(stderr, "Lo sentimos. No se puede insertar mas libros. Capacidad maxima alcanzada\n");
        }
        break;
      case 2:
        fprintf(stdout, "----Actualizar presio de un libro----\n");
        fprintf(stdout, "Ingrese el nombre del  libro a actualizar: ");
        break;
    }
  }



  return 0;
}


int menu(){
  int opc;

  fprintf(stdout, "1-Insertar un nuevo libro");
  fprintf(stdout, "\n2-Actualizar precio de un libro");
  fprintf(stdout, "\n3-Borrar un libro");
  fprintf(stdout, "\n4-Mostrar un libro");
  fprintf(stdout, "\n5-Mostrar todos los libros");
  fprintf(stdout, "\n0-Salir\n");
  fprintf(stdout, "\nIngrese una opci[on: ");

  do{
    scanf("%d", &opc);
  }while(opc < 0 || opc > 5);
  limpiarBuffer();

  return opc;
}
