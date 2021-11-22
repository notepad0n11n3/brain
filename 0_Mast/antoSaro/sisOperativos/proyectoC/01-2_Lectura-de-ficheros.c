#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

struct RGB *get_inverted_colors(char *fileHere, int limitHere) {
  // printf("%s\n", fileHere);  // print el nombre del fichero

  struct RGB *invertedHere = malloc(sizeof(struct RGB) * limitHere);

  int line_size = 16;
  char *linePuntero = malloc(sizeof(char) * line_size); //reserva en memoria para la lineas del fichero

  FILE *f = fopen(fileHere, "r");   //ABRIMOS FICHERO    "w"write    "r"read ------------------------

  int i = 0;
  while(fgets(lineWhileDes, line_size, f)) {     //  fgets   file gets string
  // fgets( 1, 2, 3) 1punteroDondeQueremosQ-almaceneLoQueLea Del fichero 2cuanto ocupa la linea 3el fichero
    printf("Linea leida: %s\n", lineWhileDes);
    if( i >= limitHere){
      printf("Error, el fichero tiene demasiadas lineas\n");
    }

    int values[3];
    char *splitWhile = strdup(lineWhileDes);
        // strdup   #include <string.h>

    for (int i = 0; i < 3; i++) {
      values[i] = atoi(strsep(&split, " ")); // ASCI TO INTEGER  ,  delimitador " " (Espacio)
    }

    free(splitWhile);
    rbg_set(&inverted[i], values[0], values[1], values[2]);
    rgb_inverted(&inverted[i++]);
  //i++;
  }
  free(lineWhileDes);

  free(linePuntero);
  fclose(f);               //CERREMOS FICHERO   -----------------------------------------------------

  return inverted;
}

int main(int argc, char **argv) {   // **argv === *argv[]  

  printf("Count: %i \n", argc);
  for (int i = 0; i < argc; i++){
    printf("Argumento %i: %s\n", i, argv[i]); //imprimiendo argumentos de lineaComandos, ::: binario argumento1 argumento2
  }

  if (argc != 2){    //numero de argumentos diferente a 2
    printf("\n--->>Uso: rgb fichero\n");
    exit(69); // <stdlib.h>  cerramos el program desde cualquier parte del programa sin necesidad de estar en el main
  }

  int limit = 4;
  //                  argc  arg count    ----    argv   arg value
  get_inverted_colors(argv[1], limit);

}

