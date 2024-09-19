#include "libmx.h"

char **mx_strsplit(const char *s, char c) {
    if (s == NULL) {
        return NULL;
    }

    int size = mx_count_words(s, c);
    char **arr = (char **)malloc((size + 1) * sizeof(char *));

    if (arr == NULL) {
        return NULL;
    }

    int i = 0;
    int word_index = 0;

    while (s[i] != '\0') {
        while (s[i] == c) {
            i++;
        }

        if (s[i] == '\0') {
            break;
        }

        int start = i;

        while (s[i] != '\0' && s[i] != c) {
            i++;
        }

        int word_length = i - start;
        char *word = mx_strnew(word_length);

        if (word == NULL) {
            for (int j = 0; j < word_index; j++) {
                 mx_strdel(&arr[j]);
            }

            free(arr);
            return NULL;
        }
        mx_strncpy(word, &s[start], word_length);
        arr[word_index++] = word;
    }
    arr[word_index] = NULL;
    return arr; 
}




