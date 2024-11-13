#include "pathfinder.h"

bool is_only_digits(const char *str) {
    if (!str || *str == '\0') return false;
    for (int i = 0; str[i]; i++) {
        if (!mx_isdigit(str[i]))
            return false;
    }
    return true;
}

