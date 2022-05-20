#include <stdio.h>
#include <string.h>

struct empledo{
  char nombre[88], apellido[88];
  float salario;
};

int main(void){
  int user_empleados, min_posicion, max_posicion;
  float salario_Minimo=88888, salario_Maximo=0;

  printf("\nIngrese la cantidad de empleados: ");
  scanf("%d",&user_empleados); getchar();

  struct empledo mango[user_empleados];

  for(int i=0; i<user_empleados; i++){
    printf("\nIngrese el nombre %d: ", i+1);
    fgets(mango[i].nombre, 88, stdin); strtok(mango[i].nombre, "\n");

    printf("\nIngrese el apellido %d: ", i+1);
    fgets(mango[i].apellido, 88, stdin); strtok(mango[i].apellido, "\n");

    printf("\nIngrese el salario %d: ", i+1);
    scanf("%f",&mango[i].salario); getchar();

    if( mango[i].salario < salario_Minimo ){
      salario_Minimo = mango[i].salario;
      min_posicion = i;
    }else if( mango[i].salario > salario_Maximo ){
      salario_Maximo = mango[i].salario;
      max_posicion = i;
    }
  }

  printf("\nEl salario Maximo es de %s %s ##=> %.2f", mango[max_posicion].nombre, mango[max_posicion].apellido, mango[max_posicion].salario);
  printf("\nEl salario Minimo es de %s %s  #=> %.2f", mango[min_posicion].nombre, mango[min_posicion].apellido, mango[min_posicion].salario);
  return 0;
}
