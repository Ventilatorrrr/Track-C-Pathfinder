#include "pathfinder.h"

bool is_empty_line(const char *line) {
    while (*line) {
        if (!mx_isspace((unsigned char)*line)) {
            return false; 
        }
        line++;
    }
    return true; 
}

