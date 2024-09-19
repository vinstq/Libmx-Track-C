#include "libmx.h"

char *mx_strcpy(char *dst, const char *src){
	while((*dst++ = *src++));

	return dst;
}



