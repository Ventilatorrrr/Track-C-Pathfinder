#include "pathfinder.h"

bool is_duplicate_route(t_route *routes, int *path, int length) {
    for (t_route *current = routes; current != NULL; current = current->next) {
        if (current->length == length) {
            bool identical = true;
            for (int i = 0; i < length; i++) {
                if (current->path[i] != path[i]) {
                    identical = false;
                    break;
                }
            }
            if (identical) {
                return true;
            }
        }
    }
    return false;
}

