#include <sys/time.h>
#include <stdint.h>

uint64_t now_usecs() {
    struct timeval t;
    gettimeofday(&t, NULL);
    return t.tv_sec*1000000+t.tv_usec;
}
