#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if(str == NULL || sub == NULL || replace == NULL) {
        return NULL;
    }

    int len_sub = mx_strlen(sub);
    int len_rep = mx_strlen(replace);
    int count = mx_count_substr(str, sub);
    int len_new = mx_strlen(str) + count * (len_rep - len_sub);
    char *new_str = mx_strnew(len_new);

    const char *current = str;
    char *res_ptr = new_str;

    while ((current = mx_strstr(current, sub)) != NULL) {
        int len_before_sub = current - str;
        mx_strncpy(res_ptr, str, len_before_sub);
        res_ptr += len_before_sub;

        mx_strcpy(res_ptr, replace);
        res_ptr += len_rep;
        current += len_sub;
        str = current;
    }
    mx_strcpy(res_ptr, str);

    return new_str;
}   



