#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void capitalize(char *s) {
    int i = 0;
    int capitalizeNext = 1;

    while (s[i] != '\0') {
        if (capitalizeNext && s[i] >= 'a' && s[i] <= 'z') {
            s[i] = s[i] - ('a' - 'A');
            capitalizeNext = 0;
        } else if (!capitalizeNext && s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] + ('a' - 'A');
        }

        if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n') {
            capitalizeNext = 1;
        }

        i++;
    }
}
