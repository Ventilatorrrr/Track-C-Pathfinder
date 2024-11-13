#include "pathfinder.h"

void merge_sort_routes(t_route **head_ref, t_sort_context *context) {
    t_route *head = *head_ref;
    t_route *a;
    t_route *b;
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }
    front_back_split(head, &a, &b);
    merge_sort_routes(&a, context);
    merge_sort_routes(&b, context);
    *head_ref = sorted_merge(a, b, context);
}

