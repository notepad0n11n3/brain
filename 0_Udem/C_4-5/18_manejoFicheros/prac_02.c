#include <stdio.h>
#include <stdlib.h>

// Lee un numeros.txt y suma los n[umeros que contiene
int main(){
  FILE *f;
  f = fopen("numeros.txt","r"); // ,"r" read  ,"w" sobreEscribir ,"a" agregar
  int suma = 0, numero;

  while(feof(f)==0){ //si feof(ficheroHere)==0  a]un hay contenido enEl archivo, else  return 1 (fin del archivo)
    fscanf(f,"%d",&numero); // leemos la linea que es un entero %d
    suma = suma +(numero);
    printf("dataFichero => %d", numero);
    printf("\tvalorSuma => %d\n", suma);
    
    if(feof(f)!=0){
      suma = suma - numero;
      printf("no suma doble, suma=> %d, numero=> %d\n",suma, numero);
    }
  }

  printf("\t\t LA RESPUESTA CORRECTA ES 102, ESTAsUMANDO 2VECES EL ]ULTIMO N[UMERO :(\n");
  printf("La suma de todos los n[umeros del fichero es: %d\n", suma);
  fclose(f);

  return 0;
}
