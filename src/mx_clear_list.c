#include "pathfinder.h"

void mx_clear_list(t_list **list) {
    while (*list != NULL) {
        t_list *temp = (*list)->next;
        free((*list)->data);
        free(*list);
        *list = temp;
    }
}

