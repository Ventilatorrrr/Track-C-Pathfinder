#include "../inc/libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    const unsigned char *ptr = (const unsigned char *)s;
    unsigned char target = (unsigned char)c;

    for (size_t i = 0; i < n; i++) {
        if (ptr[i] == target) {
            return (void *)(ptr + i); 
        }
    }
    return NULL; 
}
