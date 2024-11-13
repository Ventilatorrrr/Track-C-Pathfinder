#include "pathfinder.h"

void add_bridge(t_island **islands, char *island1_name, char *island2_name, int distance, int *current_index) {
    t_island *island1 = find_or_create_island(islands, island1_name, current_index);
    t_island *island2 = find_or_create_island(islands, island2_name, current_index);

    if (bridge_exists(island1, island2) || bridge_exists(island2, island1)) {
        write(2, "error: duplicate bridges\n", 25);
        exit(1);
    }

    add_path(island1, island2, distance);
    add_path(island2, island1, distance);
}
