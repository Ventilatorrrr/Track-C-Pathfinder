#include "pathfinder.h"

void check_arg_count(int argc) 
{
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(1);
    }
}

