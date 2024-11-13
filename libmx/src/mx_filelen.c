#include "../inc/libmx.h"

int mx_filelen(int file) 
{
    int length = 0;
    char buffer;

    while (read(file, &buffer, 1) > 0) 
    {
        length++;
    }

    lseek(file, 0, SEEK_SET);

    return length;
}

