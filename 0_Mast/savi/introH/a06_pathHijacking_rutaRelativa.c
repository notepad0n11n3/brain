#include <stdio.h>

void main()
{
  setuid(0); //c tiene una medida de protecci[on contra archivo suid, con setuid0 le damos la opcion de ejecutar el binario con los privilegios del duen~o/creador/propietario

  printf("\n\n[*] Listando procesos (/usr/bin/ps):\n\n");
  system("/usr/bin/ps");

  printf("\n\n[*] Listando procesos (ps):\n\n");
  system("ps");
}
