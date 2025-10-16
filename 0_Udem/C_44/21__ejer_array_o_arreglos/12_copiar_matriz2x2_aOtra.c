#include <stdio.h>

int main(){
  int user_data[2][2];

  for(int i=0; i<2; i++){
    for(int j=0; j<2; j++){
      printf("Posici[on %d %d: ",i+1,j+1);
      scanf("%d",&user_data[i][j]);
    }
  }  printf("\n");

  for(int i=0; i<2; i++){
    for(int j=0; j<2; j++){
      printf(" %d ", user_data[i][j] );
    }
    printf("\n");
  }

  // COPIAR MATRI
  int post_copiado[2][2];
  for(int i=0; i<2; i++){
    for(int j=0; j<2; j++){
      post_copiado[i][j] = user_data[i][j];
    }
  }

  printf("\n\t=> postCopiado={ { ");
  for(int i=0; i<2; i++){
    for(int j=0; j<2; j++){
      printf("%d ", post_copiado[i][j] );
    } 
    if(i==1)
      break;
    printf(" },{ ");
  }
  printf("} }");
  return 0;
}
