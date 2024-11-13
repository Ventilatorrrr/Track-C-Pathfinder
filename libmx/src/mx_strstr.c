#include "../inc/libmx.h"

char *mx_strstr(const char *haystack, const char *needle) 
{
    if (*needle == '\0') {
        return (char *)haystack;
    }

    int needle_len = mx_strlen(needle);

    while (*haystack) {
        if (mx_strncmp(haystack, needle, needle_len) == 0) {
            return (char *)haystack;
        }
        haystack++;
    }

    return NULL;
}

