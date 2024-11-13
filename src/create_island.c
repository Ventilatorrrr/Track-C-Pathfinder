#include "pathfinder.h"

t_island *create_island(char *name) {
    t_island *new_island = malloc(sizeof(t_island));
    if (!new_island) return NULL; 

    new_island->name = mx_strdup(name); 
    new_island->islandID = -1;  
    new_island->path = NULL;  
    new_island->next = NULL;   

    return new_island;
}

