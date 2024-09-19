#include "libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    if (s1 == NULL)
        return NULL;

    char *newStr = mx_strnew(n);

    mx_strncpy(newStr, s1, n);
    return newStr;
}


