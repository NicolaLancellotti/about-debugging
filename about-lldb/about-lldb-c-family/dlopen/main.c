#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
  printf("USER: %s\n", getenv("USER"));
  printf("HOME: %s\n", getenv("HOME"));
  return 0;
}
