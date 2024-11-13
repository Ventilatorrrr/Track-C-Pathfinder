#include "pathfinder.h"

void free_paths(t_island *island) {
    t_path *current = island->path;
    while (current != NULL) {
        t_path *next = current->nextPath;
        free(current);
        current = next;
    }
    island->path = NULL;
}

