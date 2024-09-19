#include "libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if(buf_size < 0 || fd < 0) {
        return -2;
    }

    (*lineptr) = (char *)mx_realloc(*lineptr, buf_size);
    mx_memset((*lineptr), '\0', sizeof((*lineptr)));
    size_t byte = 0;
    char buf;

    if(read(fd, &buf, 1)) {
        if (buf == delim) {
            return byte;
        }

        (*lineptr) = (char *) mx_realloc(*lineptr, byte + 1);
        (*lineptr)[byte] = buf;
        byte++;
    }
    else {
        return -1;
    }

    while (read(fd, &buf, 1)) {
        if(buf == delim) {
            break;
        }

        if(byte >= buf_size) {
            (*lineptr) = (char *) mx_realloc(*lineptr, byte + 1);
        }
        (*lineptr)[byte] = buf;

        byte++;
    }

    (*lineptr) = (char *) mx_realloc(*lineptr, byte + 1);

    size_t free_bytes = sizeof((*lineptr)) - byte;
    mx_memset(&(*lineptr)[byte], '\0', free_bytes);

    return byte + 1;
}


