#include "../inc/libmx.h"

char *mx_file_to_str(const char *file) {
    if (!file)
        return NULL;

    int fd = open(file, O_RDONLY);  
    if (fd < 0)
        return NULL;
    
    int len = mx_filelen(fd);  

    if (len < 0) {
        close(fd);
        return NULL; 
    }

    char *text = mx_strnew(len); 
    if (text == NULL) {
        close(fd);
        return NULL; 
    }

    ssize_t bytes_read = read(fd, text, len);  
    if (bytes_read < 0 || bytes_read != len) {
        close(fd);
        free(text); 
        return NULL;
    }

    close(fd);  
    return text;  
}
