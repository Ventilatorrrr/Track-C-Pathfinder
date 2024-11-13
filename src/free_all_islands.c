#include "pathfinder.h"

void free_all_islands(t_island *islands) {
    t_island *current_island = islands;
    while (current_island != NULL) {
        free_paths(current_island);
        free(current_island->name); 
        t_island *next_island = current_island->next;
        free(current_island);
        current_island = next_island;
    }
}


