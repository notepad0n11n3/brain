#include <stdio.h>

int main(){
  /*
  int dia;
  printf("Selecciona un n[umero de los d[ias de la semana (1-7):\n");
  scanf("%d",&dia);

  switch(dia){
    case 1: printf("Lunes");
            break;
    case 2: printf("Martes");
            break;
    case 3: printf("Miercoles");
            break;
    case 4: printf("Jueves");
            break;
    case 5: printf("Viernes");
            break;
    case 6: printf("Sabado");
            break;
    case 7: printf("Domingo");
            break;
    default: printf(" Opci[on invalida :(");
             break;
  }
  */

  char user_data;
  printf("Ingresa una vocal:\n");
  scanf("%c",&user_data);

  switch(user_data){
    case 'a': printf("=>a<=");
              break;
    case 'e': printf("=>e<=");
              break;
    case 'i': printf("=>i<=");
              break;
    case 'o': printf("=>o<=");
              break;
    case 'u': printf("=>u<=");
              break;
    default: printf("... %c no es una vocal :(\n",user_data);
  }
  return 0;
}
