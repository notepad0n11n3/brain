#include <stdio.h>

int main(int argc, char *argv[]){
//	int VALUE_MY_EXIT;
	int a, b;
	scanf("%d %d", &a, &b);
/*
	fprintf(stdout, "\xA\x9La suma es: %d\xA", a + b);

	if(a > b){
		fprintf(stdout, "\xA\x9Se cumple. A es mayor que b\xA");
	}else if(a < b){
		fprintf(stdout, "\xA\x9Se cumple. A es menor que b\xA");
	}else{
		fprintf(stdout, "\xA\x9A es igualmayor que b\xA");
	}

	(a > b)? (fprintf(stdout, "\xA\x9 A es mayor que B\xA", NULL), VALUE_MY_EXIT=22):
	(a < b)? (fprintf(stdout, "\xA\x9 A es MENOR que B\xA", NULL), VALUE_MY_EXIT=33):(fprintf(stdout, "LOS DOS SON IGUALES", NULL), VALUE_MY_EXIT=69);
	*/

	(a < b)? (fprintf(stdout, "*** A es menor que B, if READY...<3")):( fprintf(stdout, "### ELSE WORKING\xA"), (a == 69)? printf("69 69 69 detected"):(void)0);

	(1 != 2)? fprintf(stdout, "\xA\xA\x9 1 diferente de 2"):(void)0;

//	return VALUE_MY_EXIT;
	return 0;
}
