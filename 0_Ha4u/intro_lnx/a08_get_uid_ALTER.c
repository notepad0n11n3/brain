#include <stdio.h>
#include <unistd.h>

int main(){
  fprintf(stdout, "UID: %d, EUID: %d\n", getuid(), geteuid());
}
