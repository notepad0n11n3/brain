#include <stdio.h>

int kono(int des);

int main(){
  int user_number;
  printf("Ingrese un n[umero:\n");
  scanf("%d",&user_number); getchar();

  for( int i=user_number; i>0; i--){
    printf("%d\n", kono(i) );
  }

  return 0;
}

int kono(int des){
  if(des == 1 || des == 0){
    return 1;
  }else{
    return kono(des-1)+1; // return kono;  es suficiente, peroDale con la recursividad :) 
  }
}
