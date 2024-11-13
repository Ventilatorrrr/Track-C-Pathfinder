#include "pathfinder.h"

t_route *sorted_merge(t_route *a, t_route *b, t_sort_context *context) {
    t_route *result = NULL;
    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;

    if (context->cmp(a, b, context->islands) <= 0) {
        result = a;
        result->next = sorted_merge(a->next, b, context);
    } else {
        result = b;
        result->next = sorted_merge(a, b->next, context);
    }
    return result;
}

