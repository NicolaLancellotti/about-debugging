import Foundation
import dlopen_utility

/*
 (lldb) target module lookup --name secretMessage
 1 match found in /Users/nicola/Library/Developer/Xcode/DerivedData/about-lldb-ertlrtvjtyavebglhdssjxnvtjkg/Build/Products/Debug/dlopen_utility.framework/Versions/A/dlopen_utility:
         Address: dlopen_utility[0x0000000000003e10] (dlopen_utility.__TEXT.__text + 80)
         Summary: dlopen_utility`dlopen_utility.Foo.secretMessage() -> Swift.Int at Foo.swift:6
 
 (lldb) image dump symtab --show-mangled-names dlopen_utility
 [    9]     35 D X Code            0x0000000000003e10 0x000000010006ae10 0x0000000000000020 0x000f0000 $s14dlopen_utility3FooC13secretMessage33_F02436B5777444975D04BFA81E7F8DE9LLSiyF
 */
let foo = Foo()

if let handle = dlopen("./dlopen_utility.framework/dlopen_utility", RTLD_NOW) {
  let sym = dlsym(handle, "$s14dlopen_utility3FooC13secretMessage33_F02436B5777444975D04BFA81E7F8DE9LLSiyF")!
  typealias secretMessageType = @convention(c) (Any) -> Int
  let secretMessage = unsafeBitCast(sym, to: secretMessageType.self)
  print(secretMessage(foo))
  dlclose(handle)
}
