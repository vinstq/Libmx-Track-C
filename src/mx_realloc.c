#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    if(size == 0) {
        free(ptr);
        return NULL;
    }
    if(ptr == NULL) {
        return malloc(size);
    }

    void *new = malloc(size);
    mx_memcpy(new, ptr, size);

    free(ptr);

    return new;
}





