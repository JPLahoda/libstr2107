#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char *pad(char *s, int d) {
    if (s == NULL) {
        return NULL;
    }

    int len = 0;
    while (s[len] != '\0') {
        len++;
    }

    int paddedLen = (len / d + 1) * d;
    char *result = (char *)malloc((paddedLen + 1) * sizeof(char));
    if (result == NULL) {
        return NULL;
    }

    int i;
    for (i = 0; i < len; i++) {
        result[i] = s[i];
    }

    for (; i < paddedLen; i++) {
        result[i] = ' ';
    }
    result[i] = '\0';

    return result;
}
