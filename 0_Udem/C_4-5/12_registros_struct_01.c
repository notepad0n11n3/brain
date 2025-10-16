#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
  // Declaraci[on struct
  struct jugador{
    char nombre_here[40];
    int edad;
    float altura;
  };

  struct jugador jugadores[5];

  for(int i=0; i<5; i++){
    printf("\n\t\t Jugador #%d\n",i);
    printf("\nIngrese el nombre: ");
    fgets(jugadores[i].nombre_here, 40, stdin); strtok(jugadores[i].nombre_here, "\n");

    printf("\nIngrese la edad: ");
    scanf("%d",&jugadores[i].edad); getchar();

    printf("\nIngrese la altura: ");
    scanf("%f",&jugadores[i].altura); getchar();
  }


  int user_while=-1;
  do{
    int user_option;
    printf("\nOpciones disponibles:\n 1-Mostrar jugadores\n 2-Buscar jugador\n 3-Jugador m[as alto\n 0-Salir\n\t\t=> ");
    scanf("%d",&user_option); getchar();

    switch(user_option){
      case 1:
        for(int i=0; i<5; i++){ printf("\n\t=> Jugador #%d: %s\n",i,jugadores[i].nombre_here); }
        break;

      case 2:
        char search_namePlayer[40];
        printf("\n\t\tIngrese el nombre del jugador: ");
        fgets(search_namePlayer, 40, stdin); strtok(search_namePlayer, "\n");
        int no_encontrado=0;
        for(int i=0; i<5; i++){
          if( (strcmp(search_namePlayer, jugadores[i].nombre_here) == 0 ) ){
            printf("\n\t#=> %s, edad: %d, altura: %.2f \n",jugadores[i].nombre_here,jugadores[i].edad,jugadores[i].altura);
            no_encontrado = 1;
          }
        }
        if( no_encontrado == 0 ){
          printf("\n\t --> No encontramos al Jugador %s  :(  </3... \n",search_namePlayer);
        }
        break;

      case 3:
        float mayor_altura = jugadores[0].altura;
        char mayorAl_nombre[44];      strcpy(mayorAl_nombre, jugadores[0].nombre_here);
        int mayorAl_edad= jugadores[0].edad;
        for(int i=1; i<5; i++){
          if( jugadores[i].altura > mayor_altura ){
            mayor_altura = jugadores[i].altura;
            strcpy(mayorAl_nombre, jugadores[i].nombre_here);
            mayorAl_edad = jugadores[i].edad;
          }
        }

        printf("\n\t #=> El jugador con mayor altura es %s, edad: %d, ALTURA: %.2f\n",mayorAl_nombre ,mayorAl_edad, mayor_altura);
        break;

      case 0:
        user_while=0; system("clear"); printf("\n\tSaliendo...\n");
        break;

      default:
        system("clear"); printf("\n\t\tError...\n\t\t\tOpci[on incorrecta :(\n");
        break;
    }
  }while( user_while == -1 );

  return 0;
} 
