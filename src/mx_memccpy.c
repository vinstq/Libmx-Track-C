#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
    unsigned char *d = dst;
    unsigned char ch = (unsigned  char)c;
    const unsigned char *s = src;

    for(size_t i = 0; i < n; i++) {
        d[i] = s[i];

        if(s[i] == ch) {
            return d + i + 1;
        }
    }
    return NULL;
}



