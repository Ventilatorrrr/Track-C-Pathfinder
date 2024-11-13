#include "pathfinder.h"

void mx_clear_path_list(t_path **head) {
    t_path *current = *head;
    t_path *next;

    while (current != NULL) {
        next = current->nextPath;
        free(current); 
        current = next;
    }

    *head = NULL; 
}
