#include <stdio.h>

int main(){

	int x = 5;
	const char *resultado = (x > 0) ? "Positivo"
												: (x < 0) ? "Negativo"
																	: "Cero";

	fprintf(stdout, "\xA\x9 El numero %d es %s\xA", x, resultado);


	int nota = 85;
	const char *catagoria \
	= (nota >= 90)? "A"
	: (nota >= 80)? "B"
	: (nota >= 70)? "C"
	: (nota >= 60)? "D"
	: "F";

	fprintf(stdout, "\xA\x9 La nota de %d corresponde a %s\xA", nota, catagoria);


	int n=0;
	const char *tipo = (n == 0)? "Cero"
										: (n % 2 == 0)? "Par"
										: "Impar";

	fprintf(stdout, "\xA\x9 %d es %s \xA", n, tipo);

	int edad=17;
	int permiso = (edad >= 18)? 1 : (edad >= 16) ? 2 : 0;
	//	1=adulto, 2=parcial, 0=sin permiso
	fprintf(stdout, "\xA\xA\x9 Permiso: %d\n", permiso);

	return 0;
}
