#include <stdio.h>

int main(void){

  (1 > 3) ? printf("\nIf... ready\n") : printf("\nElse... ready\n\n");

  (1 == 1)? printf("\nif 1\n"), printf("if 2 COMA\n") : printf("else\n"), printf("else2\n\n");

  (2 == 1)? ( printf("\nif 1\n"), printf("if 2 COMA\n") ) : ( printf("else\n"), printf("else2\n") );
  return 0;
}
