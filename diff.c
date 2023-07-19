#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int diff(char *s1, char *s2) {
    int count = 0;
    while (*s1 != '\0' || *s2 != '\0') {
        if (*s1 != *s2) {
            count++;
        }
        s1++;
        s2++;
    }
    return count;
}
