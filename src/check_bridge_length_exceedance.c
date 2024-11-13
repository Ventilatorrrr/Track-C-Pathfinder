#include "pathfinder.h"

void check_bridge_length_exceedance(t_island *islands) 
{
    long long total_length = 0;

    for (t_island *island = islands; island != NULL; island = island->next) {
        t_path *path = island->path;
        while (path != NULL) {
            total_length += path->pathDistance;
            if (total_length > INT_MAX) {
                mx_printerr("error: sum of bridges lengths is too big\n");
                exit(1);
            }
            path = path->nextPath;
        }
    }
}

