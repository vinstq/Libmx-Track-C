#include "libmx.h"

char *mx_file_to_str(const char *file) {
    if(file == NULL) {
        return NULL;
    }

    int file_check = open(file, O_RDONLY);

    if(file_check < 0) {
        return NULL;
    }

    int lenght = 0;
    char buff;

    while(read(file_check, &buff, 1)) {
        lenght++;
    }

    if(close(file_check) < 0) {
        return NULL;
    }

    file_check = open(file, O_RDONLY);

    if(file_check < 0) {
        return NULL;
    }
    
    char *str = mx_strnew(lenght);

    for(int i = 0; read(file_check, &buff, 1); i++) {
        str[i] = buff;
    }
    if(close(file_check) < 0) {
        return NULL;
    }
    return str;
}

