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

char *str_connect(char **strs, int n, char c) {
    if (n <= 0 || strs == NULL) {
        return NULL;
    }

    int totalLength = 0;
    int separatorLength = 1;

    for (int i = 0; i < n; i++) {
        if (strs[i] != NULL) {
            totalLength += str_length(strs[i]);
        }
    }

    totalLength += (n - 1) * separatorLength + 1;

    char *result = (char *)malloc(totalLength * sizeof(char));
    if (result == NULL) {
        return NULL;
    }

    int index = 0;

    for (i = 0; i < n; i++) {
        if (strs[i] != NULL) {
            int len = str_length(strs[i]);
            for (int j = 0; j < len; j++) {
                result[index++] = strs[i][j];
            }
            if (i < n - 1) {
                result[index++] = c;
            }
        }
    }

    result[index] = '\0';
    return result;
}
