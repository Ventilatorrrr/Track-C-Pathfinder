#include "pathfinder.h"

bool bridge_exists(t_island *island, t_island *connect) {
    for (t_path *path = island->path; path != NULL; path = path->nextPath) {
        if (path->nextConnect == connect) {
            return true;
        }
    }
    return false;
}

