#include <stdio.h>

int main(){

  int user_number;

  printf("Ingrese el n[umero para mostrar los multiplos de 5:\n");
  scanf("%d",&user_number); getchar();

  for(int i=1; i<=user_number; i++){
    if( (i%5) == 0){ printf("%d es multiplo de 5\n",i); }
  }

  int x=1;
  while( x <= user_number ){
    if( (x%5) == 0){ printf("%d es multiplo de 5 <==\n",x);}
    x++;
  }

  int a=1;
  do{
    if( (a%5) == 0){ printf("%d es multiplo de 5 <=<=<\n",a); }
    a++;
  }while(a <= user_number);

  return 0;
}
