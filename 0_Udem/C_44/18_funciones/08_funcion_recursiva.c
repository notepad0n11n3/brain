#include <stdio.h>

    // Funcion RECURSIVA. Funcion que se llama a si misma.
long factorial_umu();

int main(){

  int user_number;
  printf("Ingrese un n[umero:\n");
  scanf("%d",&user_number); getchar();

  for(int i=0; i<=user_number; i++){
    printf("%li\n", factorial_umu(i) ); // %li  long int     long
  }
  return 0;
}

long factorial_umu( long des ){
  if( des <= 1){
    return 1;
  }else {
    return( des * factorial_umu(des-1) );
  }

}
