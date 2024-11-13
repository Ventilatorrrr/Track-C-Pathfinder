#include "pathfinder.h"

void check_file_existence(char *filename) 
{
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        mx_printerr("error: file ");
        mx_printerr(filename);
        mx_printerr(" does not exist\n");
        exit(1);
    }
    close(fd);
}

