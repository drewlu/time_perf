#include <sys/time.h>
#include <stdio.h>
#include <util.h>


int main(int argc, char *argv[]) {
    size_t n = atoi(argv[1]);
    struct timeval t;

    size_t i = 0;
    uint64_t begin = now_usecs();
    for (i=0; i<n; i++) {
        gettimeofday(&t, NULL);
    }
    uint64_t end = now_usecs();

    printf("time passed for %llu times gettimeofday():%llu(us), avg:%llu(us)\n", n, end-now, (end-now)*1.0/n);

    return 0;
}
