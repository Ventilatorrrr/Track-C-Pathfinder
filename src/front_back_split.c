#include "pathfinder.h"

void front_back_split(t_route *source, t_route **front_ref, t_route **back_ref) {
    t_route *fast;
    t_route *slow;
    if (source == NULL || source->next == NULL) {
        *front_ref = source;
        *back_ref = NULL;
    } else {
        slow = source;
        fast = source->next;
        while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        *front_ref = source;
        *back_ref = slow->next;
        slow->next = NULL;
    }
}
