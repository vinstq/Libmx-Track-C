#include "libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
  int len = 0;
  unsigned long n = 0;
  unsigned long b = 1;

  if(hex != NULL) {
    while (hex[len]) 
      len++;
  }
  else
    return n;

  for(int i = 0; i <= len; i++) {
    if (hex[len - i] >= '0' && hex[len - i] <= '9') {
      n += (hex[len - i] - 48) * b;
      b *= 16;
    }
    if (hex[len - i] >= 'A' && hex[len - i] <= 'F') {
      n += (hex[len - i] - 55) * b;
      b *= 16;
    }
    if (hex[len - i] >= 'a' && hex[len - i] <= 'f') {
      n += (hex[len - i] - 87) * b;
      b *= 16;
    }
  }
  return n;
}


