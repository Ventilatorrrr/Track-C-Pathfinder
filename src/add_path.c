#include "pathfinder.h"

void add_path(t_island *from, t_island *to, int distance) 
{
    t_path *current_path = from->path;
    while (current_path != NULL) {
        if (current_path->nextConnect == to) {
            if (current_path->pathDistance > distance) {
                current_path->pathDistance = distance;
            }
            return; 
        }
        current_path = current_path->nextPath;
    }

    t_path *new_path = malloc(sizeof(t_path));
    if (!new_path) {
        mx_printerr("error: memory allocation failed for path\n");
        exit(1);
    }

    new_path->pathDistance = distance;
    new_path->nextConnect = to;
    new_path->nextPath = from->path;
    from->path = new_path;
}

