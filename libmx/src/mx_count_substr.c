#include "../inc/libmx.h"

int mx_count_substr(const char *str, const char *sub) {

    if (str == NULL || sub == NULL) {
        return -1;
    }

    int l1 = mx_strlen(str);   
    int l2 = mx_strlen(sub);    
    int count = 0;              

    if (l2 == 0) {
        return 0;
    }

    for (int i = 0; i <= l1 - l2; ++i) {

        if (mx_strncmp(&str[i], sub, l2) == 0) {
            count++;
            i += l2 - 1; 
        }
    }

    return count;
}

