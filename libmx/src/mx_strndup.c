#include "../inc/libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    if (s1 == NULL) {
        return NULL;  
    }

    size_t len = mx_strlen(s1);

    size_t final_len = len < n ? len : n;

    char *new_str = mx_strnew(final_len);
    if (!new_str) {
        return NULL;  
    }

    mx_strncpy(new_str, s1, final_len);

    return new_str;  
}

