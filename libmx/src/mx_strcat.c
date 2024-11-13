#include "../inc/libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2) {
    int len = mx_strlen(s1);  
    char *ptr = s1 + len;  
    
    while (*s2 != '\0') {
        *ptr++ = *s2++;
    }

    *ptr = '\0';  
    return s1;   
}

