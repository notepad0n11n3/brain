#include <stdio.h>
// 1 2 3 5 8...
// 1+2=3   2+3=5 3+5=8 etc...
int main(){
  int n,i,x=0,y=1,z=1; printf("Escribe el n[umero de elementos:\n"); scanf("%i",&n); getchar();
  for( i=1; i<n; i++){
    z = x + y;
    x = y;
    y = z;
    printf("%i\n",z);
  }
  return 0;
}

#include <stdio.h>

int main(){
  int user_number, back1=1, back2=0, resultado=0;

  printf("Ingrese el n[umero:\n");
  scanf("%d",&user_number); getchar();

  for(int i=1; i<=user_number; i++){
    resultado= back1 + back2; printf("back1=> %d",back1); printf("\tback2=> %d",back2);
    back2 = back1;
    back1 = resultado;
    printf("\n=>%d\n",resultado);
  }
  return 0;
}
