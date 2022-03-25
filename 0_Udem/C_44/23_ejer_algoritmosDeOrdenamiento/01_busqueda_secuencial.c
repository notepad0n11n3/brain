#include <stdio.h>

int main(){
  int a[10]={2,4,6,8,10,12,14,16,18,20};
  int user_option;
/*
  printf("\n Tengo unos n[umero aqu[i, adivina uno: ");
  scanf("%d",&user_option); getchar();
  
  for(int i=0; i<10; i++){
    if(user_option == a[i]){
      printf("\n El n[umero %d existe en la posici[on %d \n",user_option,i);
      return 0;
    }
  }
  printf("\n\t El n[umero no existe en la lista :( \n");
  return 1;
*/

  //---------------------------------------------------------------------------------- 

  int i=0; char band='F';

  printf("Escribe un n[umero: ");
  scanf("%d",&user_option); getchar();

  while( (band == 'F')&&(i<10) ){
    if( a[i]==user_option ){
      band='V';
    }
    i++;
  }

  if( band=='F' ){
    printf("\n El n[umero no existe en la lista\n");
  }else if( band=='V' ){
    printf("\n El n[umero existe, en la posici[on %i \n",i);
  }

}


  //---------------------------------------------------------------------------------- 
int main(){

  int a[]={1,2,3,4,5,6,7,8,9,10};
  int user_data, posicion;
  char nee='f';

  printf("\n Numero de la lista: ");
  scanf("%d",&user_data); getchar();

  for(int i=0; i<(sizeof(a)/4); i++){
    if(a[i]==user_data){
      nee='t';
      posicion=i;
    }
  }

  if(nee == 't'){
    printf("\n\t\t El n[umero existe, se encuentra en la posici[on %d del array\n",posicion);
  }else if(nee == 'f'){
    printf("\n\n\t El n[umero NO existe dentro del array :( \n");
  }
  return 0;
}
