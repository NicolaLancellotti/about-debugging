#import <Cocoa/Cocoa.h>

int main(int argc, const char * argv[]) {
  @autoreleasepool {
      
  }
  /*
   (lldb) expression @"Ciao"
   (NSTaggedPointerString *) $0 = 0x26597589b13466a1 @"Ciao"
   (lldb) breakpoint set --name "-[NSControl setStringValue:]" --command "expression $arg3 = 0x2268640f59d54817" --auto-continue 1
   (lldb) thread continue
   */
  return NSApplicationMain(argc, argv);
}
