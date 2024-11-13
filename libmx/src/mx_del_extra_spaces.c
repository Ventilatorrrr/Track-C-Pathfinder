#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str) {
    if (!str) return NULL;

    int start = 0;
    int end = mx_strlen(str) - 1;
    
    while (mx_isspace(str[start])) {
        start++;
    }
    
    while (end > start && mx_isspace(str[end])) {
        end--;
    }
    
    if (start > end) {
        return mx_strnew(0);
    }

    char *new_str = mx_strnew(end - start + 1);
    if (!new_str) return NULL;

    int j = 0;
    bool space = false;

    for (int i = start; i <= end; i++) {
        if (mx_isspace(str[i])) {
            if (!space) {
                new_str[j++] = ' ';
                space = true;
            }
        } else {
            new_str[j++] = str[i];
            space = false;
        }
    }

    return new_str;
}

