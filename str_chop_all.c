#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int str_length(const char *s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

char **str_chop_all(const char *s, char c) {
    if (s == NULL) {
        return NULL;
    }

    int tokenCount = 1;
    int len = str_length(s);

    for (int i = 0; i < len; i++) {
        if (s[i] == c) {
            tokenCount++;
        }
    }

    char **tokens = (char **)malloc((tokenCount + 1) * sizeof(char *));
    if (tokens == NULL) {
        return NULL;
    }

    int tokenIndex = 0;
    int tokenStart = 0;

    for (int i = 0; i < len; i++) {
        if (s[i] == c) {
            int tokenLength = i - tokenStart;
            tokens[tokenIndex] = (char *)malloc((tokenLength + 1) * sizeof(char));
            if (tokens[tokenIndex] == NULL) {
                for (int j = 0; j < tokenIndex; j++) {
                    free(tokens[j]);
                }
                free(tokens);
                return NULL;
            }

            for (int j = 0; j < tokenLength; j++) {
                tokens[tokenIndex][j] = s[tokenStart + j];
            }
            tokens[tokenIndex][tokenLength] = '\0';

            tokenIndex++;
            tokenStart = i + 1;
        }
    }

    int tokenLength = len - tokenStart;
    tokens[tokenIndex] = (char *)malloc((tokenLength + 1) * sizeof(char));
    if (tokens[tokenIndex] == NULL) {
        for (int j = 0; j <= tokenIndex; j++) {
            free(tokens[j]);
        }
        free(tokens);
        return NULL;
    }

    for (int j = 0; j < tokenLength; j++) {
        tokens[tokenIndex][j] = s[tokenStart + j];
    }
    tokens[tokenIndex][tokenLength] = '\0';
    tokens[tokenIndex + 1] = NULL;

    return tokens;
}
