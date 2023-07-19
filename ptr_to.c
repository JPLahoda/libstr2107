#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char *ptr_to(char *h, char *n) {
    int index = find(h, n);
    if (index != -1) {
        return &h[index];
    }
    return NULL;
}
