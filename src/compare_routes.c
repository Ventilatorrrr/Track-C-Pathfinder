#include "pathfinder.h"

int compare_routes(const t_route *a, const t_route *b, t_island *islands) {
    int min_length = (a->length < b->length) ? a->length : b->length;
    for (int i = 0; i < min_length; i++) {
        const char *name_a = get_island_name_by_index(islands, a->path[i]);
        const char *name_b = get_island_name_by_index(islands, b->path[i]);
        int cmp = mx_strcmp(name_a, name_b);
        if (cmp != 0) {
            return cmp;
        }
    }
    return a->length - b->length;
}


