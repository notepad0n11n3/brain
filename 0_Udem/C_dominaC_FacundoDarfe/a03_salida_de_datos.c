#include <stdio.h>

int main(int argc, char *argv[]){
	int a = 4, b = 7, c;
	c = a + b;
	fprintf(stdout, "\xA\x9 El resultado de la suma entre %d y %d es: %d \xA", a, b, c);

	float real = 14.1516;
	fprintf(stdout, "\xA\x9 Numero \"real\" con 2 decimales: %.2f\xA", real);


	/*
		%d:  entero decimal
		%o:  octal
		%x:  hexadecimal
		%u:  entero sin signo
		%c:  tipo caracter
		%s:  cadena de caracteres STRING
		%f:  float REAL NUMBER
		%e:  float, notacion cientifica
		%g:  tipo float, convierte de %e a %f
	*/

	int num1;

	fprintf(stdout, "\xA\x9 Ingrese un entero: \xA", NULL);
	scanf("%d", &num1);
	fprintf(stdout, "\xA\x9 El Numero ingresado es: %d \xA", num1);

	int x, y;
	fprintf(stdout, "\xA\x9 Ingrese un punto en el plano de la forma x,y: ");
	scanf("%d, %d", &x, &y);
	fprintf(stdout, "\xA El punto ingresado es (%d,%d)", x, y);



	return 0;
}
