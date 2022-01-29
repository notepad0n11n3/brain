#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

  struct jugador{
    char nombre[50];
    int edad;
    float altura;
  };

  struct jugador jugadores[5];

  for(int i=0; i<5; i++){
    printf("Introduce el nombre del jugador %d\n",i+1);
    fgets(jugadores[i].nombre, 50, stdin);
    
    printf("Introduce la edad del jugador %d\n",i+1);
    scanf("%d",&jugadores[i].edad);

    printf("Introduce la altura del jugador %d\n",i+1);
    scanf("%d",&jugadores[i].altura);

    fflush(stdin);

  }


  int user_option = -1;

  while(user_option != 0){
    printf("Introduce la opci[on que deseas realizar: \n1-Listar jugador\n2-Buscar jugador\n\t3-Jugador m[as alto\n\t0-Salir");
    scanf("%d",&user_option);

    if(user_option == 1){
      for(int i=0;i<5;i++){
        printf("Jugador de nombre %s y altura %.2f",jugadores[i].nombre, jugadores[i].altura);
      }
      if(user_option == 2){
        char nombre_jugador[50];
        printf("Introduce el nombre del jugador que deseas buscar: ");
        fgets(nombre_jugador, 50, stdin);
      }
    }
  }
}
