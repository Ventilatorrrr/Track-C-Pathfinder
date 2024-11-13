#include "pathfinder.h"

t_route *add_route(int *path, int length, int distance, t_route **routes) {
    if (is_duplicate_route(*routes, path, length)) {
        return NULL;
    }

    t_route *new_route = malloc(sizeof(t_route));
    if (new_route == NULL) {
        mx_printerr("Error: Failed to allocate memory for new route\n");
        return NULL;
    }
    

    new_route->path = malloc(length * sizeof(int));
    if (new_route->path == NULL) {
        mx_printerr("Error: Failed to allocate memory for route path\n");
        free(new_route);
        return NULL;
    }
    

    new_route->length = length;
    new_route->distance = distance;

    for (int i = 0; i < length; i++) {
        new_route->path[i] = path[i];
    }

    new_route->next = *routes;
    *routes = new_route;

    return new_route;
    free_routes(*routes);
}


