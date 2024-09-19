#include "libmx.h"

int mx_count_words(const char *str, char c) {
    bool state = true;
    int count = 0;
    int i = 0;

    if(str == NULL) {
        return -1;
    }
    else{
        while(str[i] != '\0'){
            if(str[i] == c) {
                state = true;
            }
            else if(state) {
                state = false;
                count++;
            }
            i++;
        }
    }
    return count;
}


