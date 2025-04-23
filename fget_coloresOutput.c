#include <stdio.h>

int main(int argc, char **argv){

	char nombre[65];
	fprintf(stdout, "\xA\x9 Ingrese el string: \xA", NULL);

	fgets(nombre, sizeof(nombre), stdin);

	fprintf(stdout, "\xA\xA\x9\x9\033[0;31m::>>> Ready\\033[0m: %s\xA", nombre);
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
