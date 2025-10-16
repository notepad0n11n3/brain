#include <stdio.h>
#include <stdlib.h>

//          ARGUMANETOS EN LA LINEA DE COMANDOS: 
//  int argc   count de los argumentos recibidos
//  char **argv   array de strings/cadenas

struct RGB {
  int r;
  int g;
  int b;
};

void rgb_set(struct RGB *rgb, int r, int g, int b) {   // void es vacio, no DEVUELVE NADA
  if (r + g + b <= 255 * 3 && (r >= 0 && g >= 0 && b >= 0) ) {
    rgb->r = r;
    rgb->g = g;
    rgb->b = b;
  }
}

void rgb_invert(struct RGB *rgb) {
  rgb_set(rgb, 255 - rgb->r, 255 - rgb->g, 255 - rgb->b);
}


char *rgb_str(struct RGB *rgbGo) {  /* un puntero a char
char* rgb_str(struct RGB *rgbGo) {  // un puntero a char */
  char *str = malloc(sizeof(char) * 64); //reservamos memoria para la cadena de 64 caracteres

  sprintf(
      str, "RGB: (%i, %i, %i)\n HEX: 0x%02x%02x%02x", // %x es hexadecimal, %02x 2 digitosHexadecimales
      rgbGo->r, rgbGo->g, rgbGo->b, // rellenamos (%i, %i, %i)
      rgbGo->r, rgbGo->g, rgbGo->b  // rellenamos %02x %02x %02x
      ); //guarda un valor en un puntero  str

  return str;  // devolvemos el puntero

  // EL QUE OBTIENE EL PUNTERO LO LIBERA
}

int main(int argc, char **argv) {   // **argv === *argv[]  

  /*
    --------------ARGUMENTOS CONSOLA ARGUMENTOS CONSOLA --------------
  printf("Count: %i \n", argc);
  for (int i = 0; i < argc; i++){
    printf("Argumento %i: %s\n", i, argv[i]); //imprimiendo argumentos de lineaComandos, ::: binario argumento1 argumento2
  }

  if (argc != 2){    //numero de argumentos diferente a 2
    printf("\n--->>Uso: rgb fichero\n");
    exit(69); // <stdlib.h>  cerramos el program desde cualquier parte del programa sin necesidad de estar en el main
  }
  */

  // ESTO ESTA EN EL STACK like VARIABLE LOCAL
//struct RGB rgbUwU = {1, 2, 3};
  struct RGB rgbUwU = {.b = 1, .g = 2, .r = 3};  //
  printf("Color antes de invertir: (%i, %i, %i)\n", rgbUwU.r, rgbUwU.g, rgbUwU.b);
        /// rgbUwU no esta declarado como puntero, por eso el rgbUwU.r  no rgbUwU->r
  rgb_invert(&rgbUwU);  //rgbUwU no es puntero, es una variable local, rgb_invert espera un puntero, pero PODEMOS USAR LA DIRECCION DE MEMORIA con ' & '  :)

  printf("Color despues de invertir: (%i, %i, %i)\n", rgbUwU.r, rgbUwU.g, rgbUwU.b);


  // ESTO ESTA EN EL HEAP like VARIABLE GLOBAL
  struct RGB *rgbOwO = malloc(sizeof(struct RGB));

  printf("Color antes de invertir: (%i, %i, %i)\n", rgbOwO->r, rgbOwO->g, rgbOwO->b);
  rgb_invert(rgbOwO); // al ser un puntero no puede usar 'rgbOwO' sin * o & , el puntero pasa la direcci[on de memoria
  printf("Color despu[es de invertir: (%i, %i, %i)\n", rgbOwO->r, rgbOwO->g, rgbOwO->b);
  free(rgbOwO);

  struct RGB *x89p = malloc(sizeof(struct RGB));
  printf("%s\n", rgb_str(x89p));
  rgb_invert(x89p);
  printf("%s\n", rgb_str(x89p));
  free(x89p);

}

