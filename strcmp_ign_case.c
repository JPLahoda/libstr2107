#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int strcmp_ign_case(char *s1, char *s2) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        char c1 = s1[i];
        char c2 = s2[i];
        if (c1 >= 'a' && c1 <= 'z') {
            c1 -= 'a' - 'A';
        }
        if (c2 >= 'a' && c2 <= 'z') {
            c2 -= 'a' - 'A';
        }
        if (c1 != c2) {
            return c1 - c2;
        }
        i++;
    }

    if (s1[i] == '\0' && s2[i] == '\0') {
        return 0;
    } else if (s1[i] == '\0') {
        return -s2[i];
    } else {
        return s1[i];
    }
}
