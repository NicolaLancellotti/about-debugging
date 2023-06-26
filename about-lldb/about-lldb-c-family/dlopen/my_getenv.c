#import <dlfcn.h>
#import <assert.h>
#import <stdio.h>
#import <dispatch/dispatch.h>
#import <string.h>

char *getenv(const char *name) {
  static void *handle;
  static char *(*real_getenv)(const char *);
  
  static dispatch_once_t onceToken;
  dispatch_once(&onceToken, ^{
    handle = dlopen("/usr/lib/system/libsystem_c.dylib", RTLD_NOW);
    assert(handle);
    real_getenv = dlsym(handle, "getenv");
  });
  
  if (strcmp(name, "USER") == 0) {
    return "Pippo";
  }
  
  return real_getenv(name);
}
