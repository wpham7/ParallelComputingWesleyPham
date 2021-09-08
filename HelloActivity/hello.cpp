#include <unistd.h>
#include <limits.h>
#include <stdio.h>

int main () {
  char hostname[HOST_NAME_MAX];
  gethostname(hostname, HOST_NAME_MAX);
  printf("Hostname is: %s \n", hostname);
  return 0;
}
