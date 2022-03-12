#include <stdio.h>

#include <string.h>//strtok(variable, "eliminarChar");
int main(){
  char user_data[30];

  printf("Ingrese el nombre de usuario:\n");
  fgets(user_data, 30, stdin); strtok(user_data, "\n");

  char last_name[30];
  printf("Ingrese su apellido:\n");
  fgets(last_name, 30, stdin); strtok(last_name, "\n");

  printf("hello %s <3\n",user_data);
  printf("how are you %s O.O\n",last_name);



  int user_number[10];
  for(int i=0; i<10; i++){
    printf("\nIngrese la opci[on %d:",i);
    scanf("%d",&user_number[i]); getchar();
  }
  for(int i=0; i<10; i++){
    printf("%d ",user_number[i]);
  }



  printf("\n\n------------------------------\nHello "); 
  puts(user_data);
  printf("<3");
  return 0;
}
