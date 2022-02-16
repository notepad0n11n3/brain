#include <stdio.h>

int main(){
  float user_data;

  printf("Ingrese un n[umero flotante:\n");
  scanf("%f",&user_data);

  if(user_data > 10){
    printf("=> %.1f mayor a 10",user_data);
  }else if(user_data < 10){
    printf("=> %.1f menor a 10",user_data);
  }else{
    printf("dato invalido");
  }

  return 0;
}
