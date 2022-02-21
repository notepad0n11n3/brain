#include <stdio.h>

#define TARIFA1 1.2
#define TARIFA2 1.0
#define TARIFA3 0.9

int main(){
  float data_user, tarifa_luz;

  printf("Ingrese el gasto de energia:\n");
  scanf("%f",&data_user); getchar();

  if(data_user < 1000){
    tarifa_luz = TARIFA1;
  }else if(1000 < data_user && data_user < 1850){
    tarifa_luz = TARIFA2;
  }else if(data_user > 1850){
    tarifa_luz = TARIFA3;
  }

  printf("Tu consumo fue de %.2f, tu tarifa sera de %.2f\n",data_user, tarifa_luz);

  return 0;
}
