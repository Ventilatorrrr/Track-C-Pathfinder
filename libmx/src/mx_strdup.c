#include "../inc/libmx.h"

char *mx_strdup(const char *s1) {
    if (s1 == NULL) {
        return NULL; 
    }
    
    int len = mx_strlen(s1);      
    char *str1 = mx_strnew(len);  
    if (str1 != NULL) { 
        mx_strcpy(str1, s1);          
    }
    return str1;                   
}

