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

int num_in_range(char *s1, char b, char t) {
    int count = 0;
    while (*s1 != '\0') {
        if (*s1 >= b && *s1 <= t) {
            count++;
        }
        s1++;
    }
    return count;
}

int diff(char *s1, char *s2) {
    int count = 0;
    while (*s1 != '\0' || *s2 != '\0') {
        if (*s1 != *s2) {
            count++;
        }
        s1++;
        s2++;
    }
    return count;
}

void shorten(char *s, int new_len) {
    int len = 0;
    while (*s != '\0') {
        len++;
        s++;
    }
    if (new_len >= len) {
        return;
    }
    s--;
    while (len > new_len) {
        *s = '\0';
        s--;
        len--;
    }
}

int len_diff(char *s1, char *s2) {
    int len1 = 0, len2 = 0;
    while (*s1 != '\0') {
        len1++;
        s1++;
    }
    while (*s2 != '\0') {
        len2++;
        s2++;
    }
    return len1 - len2;
}

void rm_left_space(char *s) {
    int i, j = 0;
    while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n') {
        j++;
    }
    for (i = 0; s[j] != '\0'; i++, j++) {
        s[i] = s[j];
    }
    s[i] = '\0';
}

void rm_right_space(char *s) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    i--;
    while (i >= 0 && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')) {
        s[i] = '\0';
        i--;
    }
}

void rm_space(char *s) {
    rm_left_space(s);
    rm_right_space(s);
}

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

char *ptr_to(char *h, char *n) {
    int index = find(h, n);
    if (index != -1) {
        return &h[index];
    }
    return NULL;
}

int is_empty(char *s) {
    if (s == NULL) {
        return 1;
    }
    while (*s != '\0') {
        if (*s != ' ' && *s != '\t' && *s != '\n') {
            return 0;
        }
        s++;
    }
    return 1;
}

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

void take_last(char *s, int n) {
    if (s == NULL) {
        return;
    }

    int len = 0;
    while (s[len] != '\0') {
        len++;
    }

    if (n >= len) {
        return;
    }

    int i, j;
    for (i = 0, j = len - n; j <= len; i++, j++) {
        s[i] = s[j];
    }
    s[i] = '\0';
}

char *dedup(char *s) {
    if (s == NULL) {
        return NULL;
    }

    int len = 0;
    while (s[len] != '\0') {
        len++;
    }

    char *result = (char *)malloc((len + 1) * sizeof(char));
    if (result == NULL) {
        return NULL;
    }

    int i, j;
    int k = 0;
    for (i = 0; i < len; i++) {
        int isDuplicate = 0;
        for (j = 0; j < i; j++) {
            if (s[i] == s[j]) {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate) {
            result[k++] = s[i];
        }
    }
    result[k] = '\0';

    return result;
}

char *pad(char *s, int d) {
    if (s == NULL) {
        return NULL;
    }

    int len = 0;
    while (s[len] != '\0') {
        len++;
    }

    int paddedLen = (len / d + 1) * d;
    char *result = (char *)malloc((paddedLen + 1) * sizeof(char));
    if (result == NULL) {
        return NULL;
    }

    int i;
    for (i = 0; i < len; i++) {
        result[i] = s[i];
    }

    for (; i < paddedLen; i++) {
        result[i] = ' ';
    }
    result[i] = '\0';

    return result;
}

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

char *repeat(char *s, int x, char sep) {
    if (s == NULL || x <= 0) {
        return NULL;
    }

    int len = 0;
    while (s[len] != '\0') {
        len++;
    }

    int sepLen = 1;
    int resultLen = len * x + sepLen * (x - 1);

    char *result = (char *)malloc((resultLen + 1) * sizeof(char));
    if (result == NULL) {
        return NULL;
    }

    int i, j;
    int index = 0;

    for (i = 0; i < x; i++) {
        for (j = 0; j < len; j++) {
            result[index++] = s[j];
        }

        if (i < x - 1) {
            result[index++] = sep;
        }
    }

    result[index] = '\0';
    return result;
}

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

int str_length(const char *s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

char *str_connect(char **strs, int n, char c) {
    if (n <= 0 || strs == NULL) {
        return NULL;
    }

    int totalLength = 0;
    int separatorLength = 1;

    for (int i = 0; i < n; i++) {
        if (strs[i] != NULL) {
            totalLength += str_length(strs[i]);
        }
    }

    totalLength += (n - 1) * separatorLength + 1;

    char *result = (char *)malloc(totalLength * sizeof(char));
    if (result == NULL) {
        return NULL;
    }

    int index = 0;

    for (i = 0; i < n; i++) {
        if (strs[i] != NULL) {
            int len = str_length(strs[i]);
            for (int j = 0; j < len; j++) {
                result[index++] = strs[i][j];
            }
            if (i < n - 1) {
                result[index++] = c;
            }
        }
    }

    result[index] = '\0';
    return result;
}

void rm_empties(char **words) {
    if (words == NULL) {
        return;
    }

    int readIndex = 0;
    int writeIndex = 0;

    while (words[readIndex] != NULL) {
        if (str_length(words[readIndex]) > 0) {
            words[writeIndex] = words[readIndex];
            writeIndex++;
        }
        readIndex++;
    }

    words[writeIndex] = NULL;
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