#include <stdio.h>

int main(void){

  (1 > 3) ? printf("\nIf... ready\n") : printf("\nElse... ready\n\n");
  (2 == 1)? ( printf("\nif 1\n"), printf("if 2 COMA\n") ) : ( printf("else\n"), printf("else2\n") );

/*
	()? ( , ):( , );
	()? ():();
	()? : ;			// Solo si tiene una sola sentencia, para no usar el ','

	()? ()
		: ();
*/

	(1 == 3)? ( fprintf(stdout, "if ternarioREADY", NULL), fprintf(stdout, "IF TERNARIO READY", NULL)) \
		: ( fprintf(stdout, "ElSE TERNARIO READY", NULL), fprintf(stdout, " elseTernario READY mochimango", NULL));

	
	(1 == 1)? () :
	(1 == 2)? () : ();

  return 0;
}
