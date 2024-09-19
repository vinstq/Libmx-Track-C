#include "libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
    if(s1 == NULL && s2 == NULL) {
        return NULL;
    }

    if(s1 == NULL) {
        return mx_strdup(s2);
    }

    if(s2 == NULL) {
        return mx_strdup(s1);
    }

    int len1 = mx_strlen(s1);
    int len2 = mx_strlen(s2);

    char *new_str = mx_strnew(len1 + len2);

    mx_strcpy(new_str, s1);
    mx_strcat(new_str, s2);

    return new_str; 
}




