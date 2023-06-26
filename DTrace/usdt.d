#pragma D option quiet

time_profiler$target:::func_start
{ 
    time = walltimestamp;
}

time_profiler$target:::func_end
{ 
    this->diff = walltimestamp - time;
    @time[arg0, this->diff] = count();
}

dtrace:::END 
{ 
    printf("           fib(i)               ns             count\n");
    printa(@time); 
}
