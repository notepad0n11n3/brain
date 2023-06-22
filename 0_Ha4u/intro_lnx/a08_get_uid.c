#include <stdio.h>
#include <unistd.h>
#include <pwd.h>

int main(void){

  struct passwd *r_pwd = getpwuid(getuid());
  fprintf(stdout, "El Usuario Real (RUID) es %s\n", r_pwd->pw_name);

  struct passwd *e_pwd = getpwuid(geteuid());
  fprintf(stdout, "El Usuario Efectivo (EUID) es %s\n", e_pwd->pw_name);

}
