#include <stdio.h>

void foo(void) {
  printf("foo\n");
}

void bar(void) {
  printf("bar\n");
}

int main(int argc, const char * argv[]) {
  foo();
  return 0;
}

/*
 (lldb) breakpoint set --name foo
 (lldb) thread continue
 
 (lldb) disassemble --mixed

 # Instruction pointer
 (lldb) expression --format "hex" -- $rip
   (unsigned long) $1 = 0x0000000100003f40he
 
 # _____________________________________________________________________________
 # Analyze first two instructions
 (lldb) memory read --format "instruction" --count 2 0x0000000100003f40
 ->  0x100003f40: 55        push   rbp
     0x100003f41: 48 89 e5  mov    rbp, rsp
 
 # 1
 (lldb) expression --format "instruction" -- 0x55
   (int) $0 = 55  push   rbp

 # 2
 (lldb) expression --format "instruction" -- 0x4889e5
   (int) $11 = e5 89  in     eax, 0x89
 
 # It is little endian
 (lldb) expression --format "instruction" -- 0xe58948
 (int) $12 = 48 89 e5  mov    rbp, rsp

 # _____________________________________________________________________________
 (lldb) target modules lookup -rn bar
 1 match found in
         Address: change-return-value[0x0000000100003f60] (change-return-value.__TEXT.__text + 32)
         Summary: change-return-value`bar at main.c:7
 (lldb) register write $rip 0x0000000100003f60
 
 (XCode) continue
 */
