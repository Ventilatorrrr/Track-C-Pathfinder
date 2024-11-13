#include "pathfinder.h"

void add_to_list(t_list **list, int value) {
    int *data = malloc(sizeof(int));
    if (!data) {
        return;
    }
    *data = value;
    t_list *new_node = malloc(sizeof(t_list));
    if (!new_node) {
        free(data);
        return;
    }
    new_node->data = data;
    new_node->next = *list;
    *list = new_node;
}

