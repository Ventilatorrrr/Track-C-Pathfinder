#include "pathfinder.h"

char *create_bridge_key(const char *island1, const char *island2) {
    char *first = mx_strdup(island1);
    char *second = mx_strdup(island2);

   
    if (mx_strcmp(first, second) > 0) {
        char *temp = first;
        first = second;
        second = temp;
    }

    int len1 = mx_strlen(first);
    int len2 = mx_strlen(second);
    int total_len = len1 + 1 + len2 + 1; 

    char *key = malloc(total_len);
    if (!key) {
        free(first);
        free(second);
        return NULL;
    }

    mx_strcpy(key, first);
    mx_strcat(key, "-");
    mx_strcat(key, second);

    free(first);
    free(second);

    return key;
}

