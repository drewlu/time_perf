#include <stdio.h>
#include "util.h"

typedef unsigned long long ticks;
inline ticks getticks(void) {
    unsigned long long a;
    asm volatile("rdtsc" : "=a" (a) :: "memory");
    return a;
}

int main(int argc, char *argv[]) {
    size_t n = atoi(argv[1]);
    struct timeval t;

    size_t i = 0;
    uint64_t begin = now_usecs();
    for (i=0; i<n; i++) {
        getticks();
    }
    uint64_t end = now_usecs();

    printf("time passed for %llu times rdtsc():%llu(us), avg:%llu(ns)\n", n, end-begin, (end-begin)*1000/n);

    return 0;
}
