#include <stdio.h>
#include <string.h>

struct infoDireccion{
  char direccion[40];
  char ciudad[40];
  char provincia[40];
};

struct empleado{
  char nombre[40];
  struct infoDireccion dirEmpleado;
  double salario;
}empleados[2];

int main(){

  for(int i=0; i<2; i++){
    printf("\n\tEmpleado %d\n",i);

    printf("\nIngrese su nombre: ");
    fgets(empleados[i].nombre, 40, stdin); strtok(empleados[i].nombre, "\n");

    printf("\nIngrese su Direcci[on: ");
    fgets(empleados[i].dirEmpleado.direccion, 40, stdin); strtok(empleados[i].dirEmpleado.direccion, "\n");

    printf("\nIngrese su ciudad: ");
    fgets(empleados[i].dirEmpleado.ciudad, 40, stdin); strtok(empleados[i].dirEmpleado.ciudad, "\n");

    printf("\nIngrese su provincia: ");
    fgets(empleados[i].dirEmpleado.provincia, 40, stdin); strtok(empleados[i].dirEmpleado.provincia, "\n");

    printf("\nIngrese el saladio: ");
    scanf("%lf",&empleados[i].salario); getchar();
  }

  for(int i=0; i<2; i++){
    printf("\n\tDatos del empleado #%d: \n",i);
    printf("\nNombre: %s",empleados[i].nombre);
    printf("\nDirecci[on: %s",empleados[i].dirEmpleado.direccion);
    printf("\nCiudad: %s",empleados[i].dirEmpleado.ciudad);
    printf("\nProvincia: %s",empleados[i].dirEmpleado.provincia);
    printf("\nSalario: %.4lf\n",empleados[i].salario);
  }

  return 0;
}
