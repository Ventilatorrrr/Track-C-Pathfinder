#include "../inc/libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    if (!str || !sub) {
        return -2; 
    }

    int str_len = mx_strlen(str);
    int sub_len = mx_strlen(sub);

    if (sub_len > str_len) {
        return -1;
    }

    for (int i = 0; i <= str_len - sub_len; i++) {
        int j = 0;
        while (j < sub_len && str[i + j] == sub[j]) {
            j++;
        }
        if (j == sub_len) {
            return i; 
        }
    }

    return -1; 
}

