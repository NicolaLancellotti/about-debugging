#include <stdio.h>

int main(int argc, const char * argv[]) {
  int32_t x = 0x78563412;
  /*
   (lldb) expression &x
   (int32_t *) $0 = 0x00007ff7bfeff1cc
   (lldb)  memory read --size 4 --count 1 --format hex 0x00007ff7bfeff1cc
   0x7ff7bfeff1cc: 0x78563412
   (lldb)  memory read --size 2 --count 2 --format hex 0x00007ff7bfeff1cc
   0x7ff7bfeff1cc: 0x3412 0x7856
   (lldb)  memory read --size 1 --count 4 --format hex 0x00007ff7bfeff1cc
   0x7ff7bfeff1cc: 0x12 0x34 0x56 0x78
   */
  printf("%d", x);
  return 0;
}
