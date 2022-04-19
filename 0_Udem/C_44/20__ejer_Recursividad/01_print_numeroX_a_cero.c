#include <stdio.h>

void get_data(); void resDes(int goro);
int user_data;

int main(){
  get_data();
  resDes(user_data);
  return 0;
}

void get_data(){
  printf("Ingrese un n[umero:\n");
  scanf("%d",&user_data); getchar();
}

void resDes(int des){
// Si el argumento es menor que 0, ya terminamos
  if(des<0){
    return;
  }else{
    // En caso contrario, muestrame el n[umero y ejecutate a ti misma con un decremento
    printf("-> %d\n",des);
    resDes(des-1);
  }
}
