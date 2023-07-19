#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int str_length(const char *s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

void rm_empties(char **words) {
    if (words == NULL) {
        return;
    }

    int readIndex = 0;
    int writeIndex = 0;

    while (words[readIndex] != NULL) {
        if (str_length(words[readIndex]) > 0) {
            words[writeIndex] = words[readIndex];
            writeIndex++;
        }
        readIndex++;
    }

    words[writeIndex] = NULL;
}
