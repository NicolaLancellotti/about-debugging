#include <stdio.h>
#include "time_profiler_provider.h"

int fib(int n) {
  if (n <= 2) {
    return n;
  }
  return fib(n - 1) + fib(n - 2);
}

int main(int argc, const char * argv[]) {
  for (int i = 1; i < 45; ++i) {
    TIME_PROFILER_FUNC_START();
    int value = fib(i);
    TIME_PROFILER_FUNC_END(i);
    printf("fib(%d) = %d\n", i, value);
  }
  return 0;
}
