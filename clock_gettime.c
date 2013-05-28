#include <time.h>
#include <stdio.h>
#include "util.h"

int main(int argc, char *argv[]) {
    size_t n = atoi(argv[1]);
    size_t i = 0;

    struct timespec t;
    uint64_t begin = now_usecs();
    for (i=0; i<n; i++) {
        clock_gettime(CLOCK_MONOTONIC, &t);
    }
    uint64_t end = now_usecs();

    printf("time passed for %llu times clock_gettime():%llu(us), avg:%llu(ns)\n", n, end-begin, (end-begin)*1000/n);
    return 0;
}
