#include "pathfinder.h"

char *get_island_name_by_index(t_island *islands, int index) {
    int current_index = 0;
    t_island *current = islands;

    while (current != NULL) {
        if (current_index == index) {
            return current->name;
        }
        current = current->next;
        current_index++;
    }

    mx_printerr("Error\n");
    return NULL;
}

