#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

  char *pch;

  struct jugador{
    char nombre[50];
    int edad;
    float altura;
  };

  struct jugador jugadores[5];

  for(int i=0; i<5; i++){

    printf("Ingrese el nombre del jugador n[umero %d\n",i+1);
    fgets(jugadores[i].nombre, 50, stdin); strtok(jugador[i].nombre,"\n");  //<< add strtok();


    jugadores[i].nombre[strcspn(jugadores[i].nombre, "\n")]=0;
    /*pch = strchr(jugadores[i].nombre,10);
    if(pch != NULL){
      *pch='\0';
    }
    fflush(stdin); //limpiar el buffer de los \n que puedan quedar y ser recogidos por fgets en la siguienteVuelta
    */

    printf("Introduce la edad del jugador n[umero %d\n",i+1);
    scanf("%d",&jugadores[i].edad); getchar(); //<- add getchar();
    fflush(stdin); //limpiar el buffer de los \n que puedan quedar y ser recogidos por fgets en la siguienteVuelta

    printf("Introduce la altura del jugador n]umero %d\n",i+1);
    scanf("%f",&jugadores[i].altura); getchar(); //<- add getchar();

    fflush(stdin); //limpiar el buffer de los \n que puedan quedar y ser recogidos por fgets en la siguienteVuelta

  }

  int opcion_usuario=-1;
  while(opcion_usuario != 0){
    printf("Opciones disponibles:\n 1-Listar jugador\n 2-Buscar jugador\n 3-Jugador m[as alto\n 0-Salir");
    scanf("%d",&opcion_usuario); getchar();  //<- getchar();

    fflush(stdin);

    if(opcion_usuario == 1){
      for(int i=0; i<5; i++){
        printf("Jugador de nombre %s y altura %.2f\n",jugadores[i].nombre, jugadores[i].altura);
      }
    }

    if(opcion_usuario == 2){
      char nombre_jugador_user[50];
      printf("Introduce el nombre del jugador que deseas buscar\n");

      fgets(nombre_jugador_user, 50, stdin);
      pch = strchr(nombre_jugador_user, 10);
      if(pch != NULL){
        *pch = '\0';

        int encontrado = 0;
        for(int i=0; i<5; i++){
          if(strcmp(jugadores[i].nombre,nombre_jugador_user) == 0){ // comparar strings en c con strcomp()
                    // si las 2 cadenas son iguales return 0
            encontrado = 1;
            printf("La edad del jugador es %d y su altura %.2f",jugadores[i].edad, jugadores[i].altura);
          }
        }

        if(encontrado == 0){
          printf("Jugador no encontrado\n");
        }
      }
    }

    if(opcion_usuario == 3){
      float mayor_altura = jugadores[0].altura;
      char nombre_mayor_altura[50];
      int edad_mayor_altura = jugadores[0].edad;

      strcpy(nombre_mayor_altura, jugadores[0].nombre); // al nombre_mayor_altura  le asigno el valor de jugadores[0].nombre  <<--<<--<<
      for(int i=1; i<5; i++){
        if(jugadores[i].altura > mayor_altura){
          strcpy(nombre_mayor_altura, jugadores[i].nombre);
          edad_mayor_altura = jugadores[i].edad;
          mayor_altura = jugadores[i].altura;
        }
      }

      printf("El nombre del jugador de mayor altura es %s y su edad es %d\n",nombre_mayor_altura, edad_mayor_altura);
    }
  }

  return 0;
}
