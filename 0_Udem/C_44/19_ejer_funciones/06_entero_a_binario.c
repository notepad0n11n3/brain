#include <stdio.h>

void binario(int nu);

int main(){
  int user_number;

  do{
    printf("Ingrese un n[umero:\n");
    scanf("%d",&user_number); getchar();
  }while(user_number<0);

  binario(user_number);
  return 0;
}

void binario(int nu){
  printf("\nnu=>%d nu%2=>%d\n",nu,nu%2);
  if(nu>1) binario(nu/2); // if(nu>1){binario(nu/2)};
            // primero se ejecuta el printf de binario(nu/2) con el nu con su propio valor de la funcionRecursiva, despu[es regresa a esta funcion a terminar el printf con el valor local de esta instancia con el valor local de nu, se podr[ia decir que se ejecuta de adentro hacia afuera

  printf("  =>nu=%d..->nu%2=%d  ",nu,nu%2);
}
