#include "pathfinder.h"

void check_file_empty(const char *filename) 
{
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        mx_printerr("error: could not open file\n");
        exit(1);
    }

    char buffer;
    ssize_t bytes_read = read(fd, &buffer, 1);
    if (bytes_read == 0) {
        close(fd);
        mx_printerr("error: file ");
        mx_printerr(filename);
        mx_printerr(" is empty\n");
        exit(1);
    }

    close(fd);
}

