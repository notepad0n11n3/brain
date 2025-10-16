#include <stdio.h>
#include <stdlib.h>


int main(){
  int n, contador_aprobados=0, contador_suspendidos=0;
  float nota;
  
  system("clear");
  printf("\n\t\tIntroduce el n[umero de alumnos: ");
  scanf("%d",&n);

  for(int i=1; i<=n; i++){
    printf("\n\tIntroduce la nota del alumno %d",i);
    scanf("%f",&nota);

    if(nota>=5){
      contador_aprobados++;
    }
    else{
      contador_suspendidos++;
    }
  }

  printf("El n[umero de aprobador es: %d y el n[umero de suspendidos es: %d\n",contador_aprobados, contador_suspendidos);

  return 0;
}
