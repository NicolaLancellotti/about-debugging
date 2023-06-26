# DTrace

DTrace is a comprehensive dynamic tracing framework ported from Solaris.  
DTrace provides a powerful infrastructure that permits administrators
to concisely answer arbitrary questions about the behavior 
of the operating system and user programs.

## Terminology
```
dtrace -n 'provider$processID:module:function:name / predicate / { actions }' -p `pgrep -x program`
```

## Providers
- syscall
- ip
- tcp
- profile (sampling)
- dtrace
- pid
- objc
- et cetera...

List providers:
```
sudo dtrace -l | awk '{ match($2, "([a-z,A-Z]*)"); print substr($2, RSTART, RLENGTH); }' | sort -u
```

## Built-in variables
- probemod
- probefunc
- execname
- pip
- arg0-arg9
- et cetera...

## Built-in subroutines
- ustack
- printf
- stop
- raise
- system
- copyin
- copyinstr
- copyout
- copyoutstr
- et cetera...

## Variables Scope
- global (they are visible throughout the D program)
    - example: `foo`
- clause-local variables (they cannot be used in different probes)
    - example: `this->foo`
- thread local: (can be used in different probes, thread safe)
    - example: `self->foo`
    - You have to manually release them:
        - example: `self->foo = 0`

## Associative Arrays
`dictionary[1, 'a'] = 2;`

## Syscall provider

### Read opened files
Terminal 1:
```
sudo dtrace -qn 'syscall::open*:entry / execname == "TextEdit" / { printf("%s opened %s\n", execname, copyinstr(arg0)); }'
```

Terminal 2:
```
touch fileDTrace.txt
open -a TextEdit fileDTrace.txt
```

`opensnoop` uses DTrace.

### Destructive actions
Terminal 1:
```
echo Ciao! > ~/c.txt
echo ~/c.txt
echo ~/c.txt | wc -m # 20

# Replace 21 with `echo ~/c.txt | wc -m` + 1
# Replace /Users/nicola/c.txt with `echo ~/c.txt`
sudo dtrace -w -n 'syscall::open*:entry / execname == "TextEdit" && strstr(copyinstr(arg0), ".txt") != NULL && strlen(copyinstr(arg0)) >= 21 / { this->a = "/Users/nicola/c.txt"; copyoutstr(this->a, arg0, 21); }'
```

Terminal 2:
```
open -a TextEdit fileDTrace.txt
```

## PID provider
Name in `provider$processID:module:function:name` can be:
- entry
- return
    - arg0 contains the instruction offset from the beginning of the function
    - arg1 contains the return value from the function
- assembly instruction offset

```
clang fib.c -o fib_executable
sudo dtrace -F -s ./pid.d -c ./fib_executable
```

## Aggregations

### Functions:
- count             | Number of times called
- sum               | Sum of the passed in values
- avg               | Average of the passed in values
- min               | Smallest of the passed in values
- max               | Largest of the passed in values
- lquantize         | Linear frequency distribution

### Examples

```
sudo dtrace -q \
    -n 'pid$target:fib_executable:fib:entry { @aggreationVariable[arg0] = count(); }' \
    -n 'dtrace:::END  { printa(@aggreationVariable);  }' \
    -c ./fib_executable
```

```
sudo dtrace -q \
    -n 'pid$target:fib_executable:fib:entry { @aggreationVariable = lquantize(arg0, 1, 10, 1); }' \
    -n 'dtrace:::END  { printa(@aggreationVariable);  }' \
    -c ./fib_executable
```

## USDT probes - User Statically-Defined Tracing probes
```
dtrace -h -s time_profiler_provider.d
clang fib_time_profiler.c -o fib_time_profiler_executable
sudo dtrace -s ./usdt.d -c ./fib_time_profiler_executable
```

## In DTrace you cannot call programm functions
```
sudo dtrace -n 'objc$target:NSControl:-setStringValue?:entry { printf("0x%p\n", arg0); ustack();}' -p `pgrep -x Safari`
```

## Clean generated files
```
rm ~/c.txt
rm ./fileDTrace.txt
rm ./fib_executable
rm ./fib_time_profiler_executable
rm ./time_profiler_provider.h
```