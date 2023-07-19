#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void shorten(char *s, int new_len) {
    int len = 0;
    while (*s != '\0') {
        len++;
        s++;
    }
    if (new_len >= len) {
        return;
    }
    s--;
    while (len > new_len) {
        *s = '\0';
        s--;
        len--;
    }
}