#include <stdio.h>
#include <string.h>		// Obligado para strtok(user_input, "\n");

const char *COL_RED = "\033[0;31m";
const char *NO_COLOR = "\033[0m";

int main(int argc, char **argv){

	char nombre[65];
	fprintf(stdout, "\xA\x9 \033[0;33mIngrese el string:\033[0m \xA", NULL);

	fgets(nombre, sizeof(nombre), stdin); strtok(nombre, "\n");

	fprintf(stdout, "\xA\xA\x9\x9\033[0;31m::>>> Ready \033[0m: %s == \033[0;32mTestComplete\033[0m\xA", nombre);

	fprintf(stdout, "\xA\x9 nuevo %s TEST %s colores\xA", COL_RED, NO_COLOR);

	return 0;
}

/*

Reset			| \033[0m					(cierra el color asignado al output)

 Color		|   Código

Negro			| \033[0;30m
Rojo			| \033[0;31m
Verde			| \033[0;32m
Amarillo	| \033[0;33m
Azul			| \033[0;34m
Magenta		| \033[0;35m
Cyan			| \033[0;36m
Blanco		| \033[0;37m

*/
