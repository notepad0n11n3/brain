#include <stdio.h>

int main(int argc, char *argv[]){

	//   & obtiene la direccion de memoria de una variable... <3 <3 <3

	// PUNTERO 'INT' A VAR 'INT'

	int num=8;
//int *puntero = &num;		// El el puntero se almacena la direccion de memoria de la variable num


	int *punteroAnull = NULL;

	// PUNTERO GENERICO, si no sabemos a que tipo de dato va a apuntar el puntero podemos declarar como puntero generico " void *punteroGenerico; "

	void *punteroGenerico;
	int *puntero = &num;
	fprintf(stdout, "\xA\x9 Valor de num xPuntero=  %i \xA\x9 Valor de num xVariable= %i\xA", *puntero, num);
	fprintf(stdout, "\xA\x9 Direccion de Memoria de num xPuntero=  %p \xA\x9 Direccion de Memoria de num xVariable= %p\xA", &puntero, &num);

	return 0;
}
