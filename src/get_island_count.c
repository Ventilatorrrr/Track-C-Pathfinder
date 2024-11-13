#include "pathfinder.h"

int get_island_count(t_island *islands) {
    int count = 0;
    while (islands != NULL) {
        count++;
        islands = islands->next;
    }
    return count;
}
