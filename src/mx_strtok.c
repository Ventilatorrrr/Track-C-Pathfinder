#include "pathfinder.h"

char *mx_strtok(char *str, const char *delim) {
    static char *save_ptr = NULL;  
    char *token;

  
    if (str) {
        save_ptr = str;
    }

  
    if (!save_ptr || *save_ptr == '\0') {
        return NULL;
    }

    
    while (*save_ptr && mx_strchr(delim, *save_ptr)) {
        save_ptr++;
    }

  
    if (*save_ptr == '\0') {
        return NULL;
    }

    
    token = save_ptr;

   
    while (*save_ptr && !mx_strchr(delim, *save_ptr)) {
        save_ptr++;
    }

    
    if (*save_ptr) {
        *save_ptr = '\0';
        save_ptr++;
    }

    return token; 
}

