#include <stdio.h>

int fib(int n) {
  if (n <= 2) {
    return n;
  }
  return fib(n - 1) + fib(n - 2);
}

int main(int argc, const char * argv[]) {
  for (int i = 1; i < 10; ++i) {
    int value = fib(i);
    printf("fib(%d) = %d\n", i, value);
  }
  return 0;
}
