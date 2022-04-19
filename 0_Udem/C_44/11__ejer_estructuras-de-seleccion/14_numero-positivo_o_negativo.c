#include <stdio.h>

int main(){
  int user_number;

  printf("Ingrese el n[umero positivo o negativo: \n");
  scanf("%d",&user_number);

  if(user_number>=0){
    printf("El numero ingresado (%d) es positivo\n",user_number);
  }else{
    printf("El n[umero ingresado (%d) es negativo\n",user_number);
  }
  return 0;
}
