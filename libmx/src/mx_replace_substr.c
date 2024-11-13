#include "../inc/libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {

    if (!str || !sub || !replace) return NULL;

    int str_len = mx_strlen(str);
    int sub_len = mx_strlen(sub);
    int replace_len = mx_strlen(replace);

    int new_size = str_len;
    const char *ptr = str;
    
    while ((ptr = mx_strstr(ptr, sub)) != NULL) {
        new_size += replace_len - sub_len; 
        ptr += sub_len; 
    }

    char *result = mx_strnew(new_size);
    if (!result) return NULL;

    char *res_ptr = result;
    ptr = str;

    while ((ptr = mx_strstr(ptr, sub)) != NULL) {
        int len = ptr - str; 
        mx_strncpy(res_ptr, str, len); 
        res_ptr += len; 
        mx_strcpy(res_ptr, replace); 
        res_ptr += replace_len;
        ptr += sub_len; 
        str = ptr; 
    }
    
    mx_strcpy(res_ptr, str);

    return result; 
}
