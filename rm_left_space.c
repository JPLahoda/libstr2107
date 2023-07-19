#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void rm_left_space(char *s) {
    int i, j = 0;
    while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n') {
        j++;
    }
    for (i = 0; s[j] != '\0'; i++, j++) {
        s[i] = s[j];
    }
    s[i] = '\0';
}
