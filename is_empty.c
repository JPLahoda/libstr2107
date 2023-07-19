#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int is_empty(char *s) {
    if (s == NULL) {
        return 1;
    }
    while (*s != '\0') {
        if (*s != ' ' && *s != '\t' && *s != '\n') {
            return 0;
        }
        s++;
    }
    return 1;
}
