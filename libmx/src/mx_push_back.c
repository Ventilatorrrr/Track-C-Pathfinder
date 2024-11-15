#include "../inc/libmx.h"

void mx_push_back(t_list **list, void *data) {
    if (*list == NULL) {
        *list = mx_create_node(data);
        return;
    }   
    t_list *current = *list;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = mx_create_node(data);
}
