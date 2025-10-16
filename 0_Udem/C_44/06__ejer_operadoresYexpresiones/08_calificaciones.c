#include <stdio.h>

//  Cual ser[a la calificaci[on final
//    
//    55% del promedio de sus tres calificaciones parciales
//    30% de la calificaci[on del examen final
//    15% de la calificaci[on de un trabajo final

int main(){

  float p1,p2,p3,promedio_parcial,examen_final,trabajo_final;
  float porcentaje_parciales, porcentaje_examenes,porcentaje_trabajo_final,calificacion_final;

  printf("Escribe las 3 calificaciones de los examenes parciales: \n");
  scanf("%f %f %f",&p1,&p2,&p3);

  printf("Escribe la calificaci[on del examen final: \n");
  scanf("%f",&examen_final);

  printf("Escribe la calificaci[on del trabajo final: \n");
  scanf("%f",&trabajo_final);

  promedio_parcial = (p1 + p2 + p3) / 3;

  porcentaje_parciales = promedio_parcial * 0.55;
  porcentaje_examenes = examen_final * 0.30;
  porcentaje_trabajo_final = trabajo_final * 0.15;
  
  calificacion_final = porcentaje_parciales + porcentaje_examenes + porcentaje_trabajo_final;

  printf("\n\tLa nota final es=> %.2f\n",calificacion_final);

  return 0;
}
