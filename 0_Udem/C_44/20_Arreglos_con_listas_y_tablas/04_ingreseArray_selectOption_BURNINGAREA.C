#include <stdio.h>
#include <stdlib.h>

            //   void mi_funcion(int mango[], int 10);
            //   mi_funcion(array_here, size_array);         // por default creo que se pasa por referencia(los cambios afectaran al arrayOriginal)
void sumar(int user_data[]); void multiplicar(int user_data[]); void user_get(int user_data[]); void multiplos_3(int user_data[]); void por_tres(int user_data[]);

int main(){
  int user_data[10];

  user_get(user_data);

  int bucle=1;
  while(bucle==1){
    int option_user;
    printf("\n 1) Reingresar datos\n 2) Sumar los datos del array\n 3) Multiplicar datos del array\n 4) Sumar solo n[umeros divisibles por 3\n 5) Multiplicar cada elemento por 3\n 6) Salir\n");
    printf("\t:=> ");
    scanf("%d",&option_user); getchar();

    switch(option_user){
      case 1: user_get(user_data); break;
      case 2: sumar(user_data); break;
      case 3: multiplicar(user_data); break;
      case 4: multiplos_3(user_data); break;
      case 5: por_tres(user_data); break;
      case 6: system("clear");printf("\n\n\t\t Saliendo..."); bucle=0;break;
      default: system("clear"); printf("\n\n\t\t Error... Error... Error...\n"); break;
    }
  }
  return 0;
}

void user_get(int user_data[]){
  for(int i=0; i<10; i++){
    printf("\n Ingrese el n[umero para la posici[on %d: ",i);
    scanf("%d",&user_data[i]); getchar();
  }

  printf("\n\t\t=> user_data{");
  for(int i=0; i<10; i++){
    if(i==9){printf("%d",user_data[i]); break;}
    printf("%d ",user_data[i]);
  }
  printf("}\n");
}

void sumar(int desdes[]){
  system("clear");
  int resultado=0;
  for(int i=0; i<10; i++){
    resultado += desdes[i];
  }
  printf("\n La suma de todos los elementos es %d\n",resultado);
}

void multiplicar(int goroNe[]){
  system("clear");
  int resultado=1;
  for(int i=0; i<10; i++){
    resultado *= goroNe[i];
  }
  printf("\n El resultado de la multiplicaci[on de los elementos es: %d\n",resultado);
}

void multiplos_3(int wiwuwiwu[]){
  int resultado=0;
  for(int i=0; i<=9; i++){
    if( (wiwuwiwu[i]%3) == 0){
      resultado += wiwuwiwu[i];
    }
  }
  printf("\n La suma de los multiplos de 3 en el array es %d\n",resultado);
}

void por_tres(int qpqpqp[]){
  system("clear"); printf("\n\t Multiplicar cada elemento del array por 3\n");
  for(int i=0; i<=9; i++){
    printf("%d x 3 => %d\n",qpqpqp[i], (qpqpqp[i]*3) );
  }
}

