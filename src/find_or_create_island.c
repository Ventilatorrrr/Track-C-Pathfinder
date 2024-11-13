#include "pathfinder.h"

t_island *find_or_create_island(t_island **islands, char *name, int *current_index) {
    t_island *current = *islands;

    while (current != NULL) {
        if (mx_strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }

    t_island *new_island = create_island(name);
    new_island->islandID = *current_index;

    (*current_index)++;
    new_island->next = *islands;
    *islands = new_island;

    return new_island;
}

