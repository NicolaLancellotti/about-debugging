provider time_profiler {
    probe func_start();
    probe func_end(int);
};
