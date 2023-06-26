#import <Foundation/Foundation.h>
#include "NLClass.h"

NLClass* make(void) {
  NLClass *instance = [[NLClass alloc] init];
  /*
   (lldb) language objc class-table dump --verbose NLClass
     isa = 0x100008150 name = NLClass instance size = 12 num ivars = 1 superclass = NSObject
       ivar name = _value type = int size = 4 offset = 8
     ...
   
   (lldb) expression instance
     (NLClass *) $1 = 0x0000600000008030
   
   (lldb) expression --format "hex" -- 0x0000600000008030 + 8
     (long) $2 = 0x0000600000008038
   (lldb) watchpoint set expression --size 4 --watch write -- 0x0000600000008038
   (lldb) thread continue
   */
  return instance;
}

void setValue(NLClass* instance, int value) {
  instance.value = value;
}

int main(int argc, const char * argv[]) {
  @autoreleasepool {
    NLClass *instance = make();
    setValue(instance, 10);
  }
  return 0;
}
