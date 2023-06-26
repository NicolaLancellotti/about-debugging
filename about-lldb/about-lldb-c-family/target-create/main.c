/*
 clang -g main.c
 lldb
 (lldb) target create ./a.out
 (lldb) breakpoint set --name increment
 (lldb) process launch
 (lldb) thread step-over
 (lldb) expression -- x
 (lldb) thread continue
 */

#include <stdio.h>

int increment(int x) {
  int y = x + 1;
  return y;
}

int main(int argc, const char * argv[]) {
  printf("%d", increment(10));
  return 0;
}
