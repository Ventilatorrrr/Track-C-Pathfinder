#include "pathfinder.h"

int get_island_index(t_island *islands, const char *name) {
    int index = 0;
    t_island *current = islands;

    while (current != NULL) {
        if (mx_strcmp(current->name, name) == 0) {
            return index; 
        }
        current = current->next;
        index++;
        
    }

    return -1;  
}


