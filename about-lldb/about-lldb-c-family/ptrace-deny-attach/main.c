#include <stdio.h>
#include <sys/ptrace.h>

int main(int argc, const char * argv[]) {
  ptrace(PT_DENY_ATTACH, 0, NULL, 0);
  printf("Hello, World!\n");
  return 0;
}

/*
 sudo dtrace -qn 'syscall::ptrace:entry { printf("%s(%d, %d, %d, %d) from %s\n", probefunc, arg0, arg1, arg2, arg3, execname); }'
 
 sudo lldb -n "ptrace-deny-attach" -w
 (lldb) target modules lookup --symbol ptrace
 (lldb) breakpoint set --func-regex ptrace --shlib libsystem_kernel.dylib
 (lldb) continue
 (lldb) thread return 0
 (lldb) continue
 */
