#include "pathfinder.h"

void mx_clear_island_list(t_island **head) {
    t_island *current = *head;
    t_island *next;

    while (current != NULL) {
        next = current->next;
        free(current->name);
        free(current); 
        current = next;
    }

    *head = NULL; 
}
