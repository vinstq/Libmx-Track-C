#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    const char *p = haystack;
    int len = mx_strlen(needle);

    for (; (p = mx_strchr(p, *needle)) != 0; p++) {
      if (mx_strncmp(p, needle, len) == 0) {
      return (char *)p;
      }
    }
    return NULL;
}



