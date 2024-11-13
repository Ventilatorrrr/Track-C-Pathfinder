#include "pathfinder.h"

bool is_only_letters(const char *str) {
    if (!str || *str == '\0') return false;
    for (int i = 0; str[i]; i++) {
        if (!mx_isalpha(str[i]))
            return false;
    }
    return true;
}
