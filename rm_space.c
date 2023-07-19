#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void rm_space(char *s) {
    rm_left_space(s);
    rm_right_space(s);
}
