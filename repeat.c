#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char *repeat(char *s, int x, char sep) {
    if (s == NULL || x <= 0) {
        return NULL;
    }

    int len = 0;
    while (s[len] != '\0') {
        len++;
    }

    int sepLen = 1;
    int resultLen = len * x + sepLen * (x - 1);

    char *result = (char *)malloc((resultLen + 1) * sizeof(char));
    if (result == NULL) {
        return NULL;
    }

    int i, j;
    int index = 0;

    for (i = 0; i < x; i++) {
        for (j = 0; j < len; j++) {
            result[index++] = s[j];
        }

        if (i < x - 1) {
            result[index++] = sep;
        }
    }

    result[index] = '\0';
    return result;
}
