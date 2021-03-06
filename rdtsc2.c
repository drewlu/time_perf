#include <stdio.h>
#include <sched.h>
#include "util.h"


/**
 * FIXME: the RDTSC instruction is incorrect in some situation,
 * please refer to http://www.strchr.com/performance_measurements_with_rdtsc
 * for more information

 * solutions to reduce issue
 * 1. use CPUID instruction to enforce flush cpu cache, maybe penalty, and inject extra 200 cycles
 * 2. bind to cpu
 */

inline uint64_t GetRDTSC() {
   asm("XOR %eax, %eax\n\t"
       "CPUID\n\t"
       "RDTSC");
}

void init_rdtsc() {
    unsigned long cpuMask = 2; /* bind to cpu 1 */
    sched_setaffinity(0, sizeof(cpuMask), &cpuMask);
}

int main(int argc, char *argv[]) {
    size_t n = atoi(argv[1]);
    struct timeval t;

    size_t i = 0;
    init_rdtsc();
    uint64_t begin = now_usecs();
    for (i=0; i<n; i++) {
        GetRDTSC();
    }
    uint64_t end = now_usecs();

    printf("time passed for %llu times RDTSC+CPUID():%llu(us), avg:%llu(ns)\n", n, end-begin, (end-begin)*1000/n);

    return 0;
}
