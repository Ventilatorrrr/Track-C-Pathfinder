#include "pathfinder.h"

void free_routes(t_route *routes) {
    t_route *current = routes;
    while (current != NULL) {
        t_route *next = current->next;
        free(current->path);
        free(current);
        current = next;
    }
}                                  
