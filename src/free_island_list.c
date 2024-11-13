#include "pathfinder.h"

void free_island_list(t_island *islands) {
    while (islands != NULL) {
        t_island *temp = islands;
        islands = islands->next;
        clear_paths(temp->path); 
        free(temp->name);       
        free(temp);              
    }
}



