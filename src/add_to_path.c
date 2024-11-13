#include "pathfinder.h"

void add_to_path(t_route *route, int island_id) {
    if (route->length >= route->capacity) {
        int new_capacity = route->capacity * 2;
        int *new_path = malloc(new_capacity * sizeof(int));

        if (!new_path) {
            mx_printerr("Memory allocation failed in add_to_path\n");
            return;
        }

        for (int i = 0; i < route->length; i++) {
            new_path[i] = route->path[i];
        }

        free(route->path);
        route->path = new_path;
        route->capacity = new_capacity;
    }

    route->path[route->length++] = island_id;
}

