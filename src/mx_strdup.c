#include "libmx.h"

char *mx_strdup(const char *s1) {
    if (s1 == NULL)
        return NULL;
        
    int size = mx_strlen(s1);
    char *newStr = mx_strnew(size);
    
    mx_strcpy(newStr, s1);
    return newStr;
}



