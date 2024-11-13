#include "../inc/libmx.h"

int mx_strlen(const char *s) {
    if (s == NULL) {
        return 0; 
    }
    
    const char *ptr = s;
    while (*ptr) {
        ptr++;
    }
    return ptr - s;
}
