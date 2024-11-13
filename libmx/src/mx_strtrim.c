#include "../inc/libmx.h"

char *mx_strtrim(const char *str)
{
    if (str == NULL) {
        return NULL;
    }
    
    int len = mx_strlen(str);
    int start = 0, end = len - 1;
    
    while (start <= end && mx_isspace(str[start])) {
        start++;
    }
    
    while (end >= start && mx_isspace(str[end])) {
        end--;
    }
    
    int new_len = end - start + 1;
    
    if (new_len <= 0) {
        return mx_strnew(0);
    }

    char *trimmed_str = mx_strnew(new_len);
    if (trimmed_str == NULL) {
        return NULL; 
    }
    
    for (int i = 0; i < new_len; i++) {
        trimmed_str[i] = str[start + i];
    }
    
    return trimmed_str;
}

