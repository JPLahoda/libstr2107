#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void take_last(char *s, int n) {
    if (s == NULL) {
        return;
    }

    int len = 0;
    while (s[len] != '\0') {
        len++;
    }

    if (n >= len) {
        return;
    }

    int i, j;
    for (i = 0, j = len - n; j <= len; i++, j++) {
        s[i] = s[j];
    }
    s[i] = '\0';
}
