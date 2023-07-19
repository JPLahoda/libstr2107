#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char *dedup(char *s) {
    if (s == NULL) {
        return NULL;
    }

    int len = 0;
    while (s[len] != '\0') {
        len++;
    }

    char *result = (char *)malloc((len + 1) * sizeof(char));
    if (result == NULL) {
        return NULL;
    }

    int i, j;
    int k = 0;
    for (i = 0; i < len; i++) {
        int isDuplicate = 0;
        for (j = 0; j < i; j++) {
            if (s[i] == s[j]) {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate) {
            result[k++] = s[i];
        }
    }
    result[k] = '\0';

    return result;
}
