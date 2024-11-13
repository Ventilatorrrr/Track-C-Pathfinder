#include "pathfinder.h"

void add_to_visited(t_visited_path **visited, const char *from, const char *to) {
    t_visited_path *new_path = malloc(sizeof(t_visited_path));
    if (!new_path) return; 

    char *temp = mx_strjoin(from, " -> ");
    new_path->path = mx_strjoin(temp, to);
    free(temp); 

    new_path->next = *visited;
    *visited = new_path;
}
