#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char *str_zip(char *s1, char *s2) {
    int len1 = 0, len2 = 0;
    while (s1[len1] != '\0') {
        len1++;
    }
    while (s2[len2] != '\0') {
        len2++;
    }
    int totalLen = len1 + len2;
    char *result = (char *)malloc((totalLen + 1) * sizeof(char));
    if (result == NULL) {
        return NULL;
    }

    int i = 0, j = 0, k = 0;
    while (i < len1 && j < len2) {
        result[k++] = s1[i++];
        result[k++] = s2[j++];
    }

    while (i < len1) {
        result[k++] = s1[i++];
    }

    while (j < len2) {
        result[k++] = s2[j++];
    }

    result[k] = '\0';
    return result;
}
