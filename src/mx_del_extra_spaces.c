#include "libmx.h"

char *mx_del_extra_spaces(const char *str) {
    if (str == NULL)
        return NULL;

    char *trimmed_str = mx_strtrim(str);
    char *cleaned_str = mx_strnew(mx_strlen(trimmed_str));
    int i = 0;
    int j = 0;

    while (trimmed_str[i] != '\0') {
        if (!mx_isspace(trimmed_str[i])) {
            cleaned_str[j++] = trimmed_str[i++];
        } else {
            cleaned_str[j++] = ' ';
            while (mx_isspace(trimmed_str[i]))
                i++;
        }
    }
    cleaned_str[j] = '\0';
    mx_strdel(&trimmed_str);

    return cleaned_str;
}




