#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    const char *p = str;
    int len = mx_strlen(sub);
    int index = 0;

    if(str == NULL) {
        return -2;
    }

    while(*p) {
        if (mx_strncmp(p, sub, len) == 0) {
            return index;
        }
        p++;
        index++;
    }
    return -1;
}

