#include <stdio.h>
#include <stdlib.h>

int main(){
  struct hora_entrada{
    int hora;
    int minuto;
  };

  struct entrada{
    struct hora_entrada hora1;
    int asistentes;
    float precio;
  };

  struct entrada ruru;

  char continuar = 's';

  while (continuar == 's'){
    printf("Introduce la hora de entrada:\n");
    scanf("%d",&ruru.hora1.hora);

    printf("Introduce el minuto de entrada:\n");
    scanf("%d",&ruru.hora1.minuto);

    printf("Introduce el n]umero de asistentes:\n");
    scanf("%d",&ruru.asistentes);

    int total = 0;

    for(int i=0; i<ruru.asistentes; i++){
      int edad;
      printf("Introduce la edad del asistente %d\n", (i+1) );
      scanf("%d",&edad);
      if(edad < 6){
        total = total + 0;
      }
      else if(edad >= 6 && edad <=15){
        total = total + 5;
      }
      else if( (edad >= 16 && edad <= 26) || edad > 65 ){
        total = total + 8;
      }
      else{
        total = total + 10;
      }
    }
    if(ruru.asistentes >= 5){
      ruru.precio = total - total*0.1;
    }
    else{
      ruru.precio = total;
    }

    printf("Hora de entrada del grupo: %d\n", ruru.hora1.hora);
    printf("Minuto de entrada del grupo: %d\n", ruru.hora1.minuto);
    printf("Precio de las entradas del grupo: %.2f\n", ruru.precio);

    printf("Quiere continuar con otro grupo? (s/n): ");
    scanf("%c",&continuar);
    while(continuar == '\n'){
      scanf("%c",&continuar);
    }
  }

  return 0;
}
