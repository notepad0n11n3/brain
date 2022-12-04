#include <stdio.h>

int main(int argc, char *argv[]){

  int mi_array[] = { 100, 200, 300 };

  int cantidad_array = sizeof(mi_array) / sizeof(mi_array[0]);    // un int tiene 4 bites, sizeof(mi_array)  4*3 = 12,  12/4 = 3 <--
  int nee = sizeof(mi_array[0]);

  fprintf(stdout, "\n %d \n", nee);
  fprintf(stdout, "\n %d \n", cantidad_array);

  for(int i=0; i < cantidad_array; i++){
    fprintf(stdout, "%d\n", mi_array[i]);
  }

  return 0;
}
