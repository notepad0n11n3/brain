#include <stdio.h>

#include <stdlib.h>

       /* ::: gcc 16_programa_menu.c
              usr/bin/ld: /tmp/cceNao06.o: in function `main':
              16_programa_menu.c:(.text+0xce): undefined reference to `pow'
              collect2: error: ld returned 1 exit status                        */

              ////  ::: gcc 16_programa*.c -ln

#include <math.h>
int main(){
  int user_option;

  printf("\n1) Cuadrado de un n[umero\n2) Numero par o impar\n3) salir\n");
  printf("\tIngrese su opci[on: ");
  scanf("%d",&user_option);

  switch(user_option){
    case 1: 
      int cubo_user, cubo_respuesta;
      printf("\nOpci[on 1 ready...  cubo de un n[umero\n");
      printf("Ingresa un n[umero: ");
      scanf("%d",&cubo_user);
    //cubo_respuesta = cubo_user * cubo_user;
      cubo_respuesta = pow(cubo_user,3);
      printf("El cuadrado de %d es: %d\n",cubo_user,cubo_respuesta);
      break;
    case 2:
      int number_user;
      printf("Numero par o impar\n");
      printf("Ingresa un n[umero: ");
      scanf("%d",&number_user);
      if((number_user%2)==0){
        printf("El n]umero %d es par\n",number_user);
      }else{
        printf("El n[umero %d es impar\n",number_user);
      }
      break;
    case 3:
      system("clear");
      printf("\n\n\t...Saliendo...\n");
      break;
  }

  return 0;
}
