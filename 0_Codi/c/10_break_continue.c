
#include <stdio.h>

int main()
{
/*
  int num=0;
  while(num<=7)
  {
    if(num==2)
    {
      break;  // llegando a 2 rompera el ciclo
    }
    printf("%i\n",num);
    num++;
  }
*/
  int num=0;
  while(num<=7)
  {
    num++;
    if(num==2)
    {
      continue; // se salta el print, no mostrara el 2
    }
    printf("%i\n",num);
  }
}
