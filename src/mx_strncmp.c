#include "libmx.h"

int mx_strncmp(const char *s1, const char *s2,int n) {
    while(n--) {
	    if(*s1 != *s2) {
		    return(*(unsigned char *)s1 - *(unsigned char *)s2);
	    }
	    s1++;
	    s2++;
    }
    return 0;
}


















