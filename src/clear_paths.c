#include "pathfinder.h"

void clear_paths(t_path *path) {
    while (path != NULL) {
        t_path *temp = path;
        path = path->nextPath;
        free(temp);
    }
}

