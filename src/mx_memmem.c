#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    const unsigned char *bptr = (const unsigned char *)big;
    const unsigned char *lptr = (const unsigned char *)little;
    
    if(little_len == 0 ||big_len == 0 || little_len > big_len) {
        return NULL;
    }

    for(size_t i = 0; i < big_len; i++) {
        if(bptr[i] == lptr[0]) {
            if(mx_memcmp(&bptr[i], lptr, little_len) == 0){
                return (void *)&bptr[i];
            }
        }
    }
    return NULL;
}



