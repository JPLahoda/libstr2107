#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int ends_with_ignore_case(char *s, char *suff) {
    if (s == NULL || suff == NULL) {
        return 0;
    }

    int i = 0;
    int j = 0;

    while (s[i] != '\0') {
        i++;
    }

    while (suff[j] != '\0') {
        j++;
    }

    while (i > 0 && j > 0) {
        i--;
        j--;

        char c1 = tolower(s[i]);
        char c2 = tolower(suff[j]);

        if (c1 != c2) {
            return 0;
        }
    }

    if (j > 0) {
        return 0;
    }

    return 1;
}
