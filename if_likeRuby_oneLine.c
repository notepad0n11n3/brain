#include <stdio.h>

int main(void){

	int a=69;

	(a != 0)? fprintf(stderr, "Error... error"):(void)0;
//				(void)0  ===   0   ===   NULL
			//			(void)0		-> es la mejor forma de decir NO HAGAS NADA en el else del ternario... <3 <3 <3


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

//(1 == 3)? ( fprintf(stdout, "if ternarioREADY", NULL), fprintf(stdout, "IF TERNARIO READY", NULL)):( (void)0 );
	
	(a == 1)? () :
	(a == 2)? () : 
	(a == 3)? () : (void)0 ;

  return 0;
}
