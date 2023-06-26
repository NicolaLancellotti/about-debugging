#pragma D option quiet

pid$target:fib_executable:fib:entry
{ 
  printf("fib(%d)\n", arg0);
}

pid$target:fib_executable:fib:return
{
  printf("returns %d\n", arg1);
}

