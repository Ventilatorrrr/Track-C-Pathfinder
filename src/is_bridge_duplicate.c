#include "pathfinder.h"

bool is_bridge_duplicate(t_list *keys, const char *key) {
    for (t_list *node = keys; node != NULL; node = node->next) {
        if (mx_strcmp((char *)node->data, key) == 0) {
            return true;
        }
    }
    return false;
}

