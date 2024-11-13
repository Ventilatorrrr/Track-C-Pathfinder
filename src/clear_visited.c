#include "pathfinder.h"

#include "pathfinder.h"

void clear_visited(t_visited_path **visited) {
    t_visited_path *current = *visited;
    while (current != NULL) {
        t_visited_path *temp = current->next;
        free(current->path);  
        free(current);       
        current = temp;
    }
    *visited = NULL;
}

