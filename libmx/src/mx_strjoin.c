#include "../inc/libmx.h"

char *mx_strjoin(char const *s1, char const *s2) 
{
    if (s1 == NULL && s2 == NULL) {
        return NULL;
    }
    if (s1 == NULL) {
        return mx_strdup(s2);
    }
    if (s2 == NULL) {
        return mx_strdup(s1);
    }

    int len1 = mx_strlen(s1);
    int len2 = mx_strlen(s2);
    char *str = mx_strnew(len1 + len2);

    if (str == NULL) {
        return NULL; 
    }

    mx_strcpy(str, s1);
    mx_strcat(str, s2);

    return str;
}
