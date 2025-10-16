#include <stdio.h>

int parDes();

int main(){
  int user_number, x;
  printf("Ingrese un n[umero:\n");
  scanf("%d",&user_number); getchar();

  x=parDes(user_number);

  if(x == 0){
    printf("El n[umero %d es par\n", user_number);
  }else {
    printf("El n[umero %d es impar\n", user_number);
  }

  return 0;
}

int parDes(int goro){
  if(goro%2 == 0){
    return 0;
  }else{
    return 1;
  }
}
