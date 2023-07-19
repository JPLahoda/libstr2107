#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int find(char *h, char *n) {
    int i, j, start;
    for (i = 0; h[i] != '\0'; i++) {
        if (h[i] == n[0]) {
            start = i;
            j = 0;
            while (h[i] != '\0' && n[j] != '\0' && h[i] == n[j]) {
                i++;
                j++;
            }
            if (n[j] == '\0') {
                return start;
            }
            i = start;
        }
    }
    return -1;
}
