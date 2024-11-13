#include "../inc/libmx.h"

int mx_count_words(const char *str, char c) {
    if (str == NULL) {
        return -1;
    }

    int count = 0;
    int length = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == c) {
            if (length > 0) { 
                count++;
                length = 0; 
            }
        } else {
            length++;
        }
    }
    if (length > 0) {
        count++;
    }

    return count;
}

