#include "pathfinder.h"

void clear_list(t_list **list) {
    t_list *current = *list; 
    while (current != NULL) {
        t_list *temp = current;
        current = current->next;
        free(temp->data);
        free(temp);
    }
    *list = NULL; 
}

