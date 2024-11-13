#include "pathfinder.h"

char *mx_read_file(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        mx_printerr("error: file does not exist\n");
        exit(1);
    }

    int buffer_size = 1024;
    char *content = malloc(buffer_size);
    if (!content) {
        close(fd);
        mx_printerr("error: memory allocation failed\n");
        exit(1);
    }

    int total_bytes = 0;
    int bytes_read;

    while ((bytes_read = read(fd, content + total_bytes, buffer_size - total_bytes - 1)) > 0) {
        total_bytes += bytes_read;

        
        if (total_bytes >= buffer_size - 1) {
            buffer_size *= 2; 
            char *new_content = malloc(buffer_size);
            if (!new_content) {
                free(content);
                close(fd);
                mx_printerr("error: memory allocation failed\n");
                exit(1);
            }
            mx_strcpy(new_content, content);
            free(content);
            content = new_content;
        }
    }

    close(fd);

    if (total_bytes == 0) {
        free(content);
        mx_printerr("error: file is empty\n");
        exit(1);
    }

    content[total_bytes] = '\0'; 
    return content;
}

