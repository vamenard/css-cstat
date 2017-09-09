#include <stdlib.h>
#include <string.h>

#include "util.h"

char* concat(const char *s1, const char *s2){
    const size_t len1 = strlen(s1);
    const size_t len2 = strlen(s2);
    char *result = malloc(len1+len2+1);

    memcpy(result, s1, len1);
    memcpy(result+len1, s2, len2+1);
    return result;
}


char* itoa(int val, int base) {
    static char buf[32] = {0};
    int i = 30;
    for(; val && i ; --i, val /= base)
        buf[i] = "0123456789abcdef"[val % base];
    return &buf[i+1];
}

