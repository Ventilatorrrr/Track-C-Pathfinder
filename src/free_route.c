#include "pathfinder.h"

void free_route(t_route *route) {
    if (route) {
        free(route->path);
        free(route);
    }
}

