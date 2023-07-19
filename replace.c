#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char *replace(char *s, char *pat, char *rep) {
    if (s == NULL || pat == NULL || rep == NULL) {
        return NULL;
    }

    int sLen = 0;
    int patLen = 0;
    int repLen = 0;

    while (s[sLen] != '\0') {
        sLen++;
    }

    while (pat[patLen] != '\0') {
        patLen++;
    }

    while (rep[repLen] != '\0') {
        repLen++;
    }

    int count = 0;

    for (int i = 0; i <= sLen - patLen; i++) {
        int found = 1;
        for (int j = 0; j < patLen; j++) {
            if (s[i + j] != pat[j]) {
                found = 0;
                break;
            }
        }
        if (found) {
            count++;
        }
    }

    int resultLen = sLen + count * (repLen - patLen);
    char *result = (char *)malloc((resultLen + 1) * sizeof(char));
    if (result == NULL) {
        return NULL;
    }

    int k = 0;
    
    for (i = 0; i <= sLen - patLen; i++) {
        int found = 1;
        for (j = 0; j < patLen; j++) {
            if (s[i + j] != pat[j]) {
                found = 0;
                break;
            }
        }
        if (found) {
            for (j = 0; j < repLen; j++) {
                result[k++] = rep[j];
            }
            i += patLen - 1;
        } else {
            result[k++] = s[i];
        }
    }

    for (; i < sLen; i++) {
        result[k++] = s[i];
    }

    result[k] = '\0';
    return result;
}
