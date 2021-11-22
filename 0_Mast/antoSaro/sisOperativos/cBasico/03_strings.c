#include <stdio.h>
#include <stdlib.h>
      // char    caracter      1bite      // char    caracter      1bite
int main() {
//char c[] = {'H','e','l','l','o','\0'};  todas las cadenas necesitan \0 al final
  char c[] = "Hello";  //tenemso ayudaSintactica
  
  char *c = malloc(sizeof(char) * 6);  //   H e l l o \0   -->> 6 bites 
    // un puntero que apunta al Heap (malloc)
  
  printf("%s\n",c);

  free(c); // liberar espacioDeMemoriaPuntero despu[es del print
}
