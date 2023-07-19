#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int all_letters(char *s) {
    while (*s != '\0') {
        if ((*s < 'A' || *s > 'Z') && (*s < 'a' || *s > 'z')) {
            return 0;
        }
        s++;
    }
    return 1;
}