#include "../inc/libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if (fd < 0 || buf_size == 0 || !lineptr) {
        return -2;
    }

    ssize_t bytes_read;
    size_t current_length = 0;
    int delim_found = 0;
    char *buffer = (char *)malloc(buf_size);

    if (!buffer) {
        return -2;
    }

    while ((bytes_read = read(fd, &buffer[current_length], 1)) > 0) {
        if (buffer[current_length] == '\r') {
            continue; 
        }

        if (buffer[current_length] == delim) {
            delim_found = 1;
            break;
        }

        current_length++;

        if (current_length >= buf_size) {
            buf_size *= 2; 
            char *new_buffer = realloc(buffer, buf_size);
            if (!new_buffer) {
                free(buffer);
                return -2;
            }
            buffer = new_buffer;
        }
    }

    if (bytes_read == 0 && current_length == 0) {
        free(buffer);
        return -1; 
    }

    buffer[current_length] = '\0'; 
    *lineptr = buffer;

    return delim_found ? current_length : -1;
}



