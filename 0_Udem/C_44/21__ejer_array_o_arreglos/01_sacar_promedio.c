#include <stdio.h>

int main(){
  int x[8], total=0;

  for(int i=0; i<8; i++){
    printf("\nDato %d: ",(i+1) );
    scanf("%d",&x[i]); getchar();
    total += x[i];
  }

  float promedio = total/8;
  printf("\n\n\t El promedio de los valores es: %.2f",promedio);
  return 0;
}
