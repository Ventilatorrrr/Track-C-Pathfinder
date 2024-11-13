#include "pathfinder.h"

void print_route(int *prev, int end, t_island *islands, int island_count) {
    if (prev == NULL) {
        mx_printerr("Route not found or is empty\n");
        return;
    }

    int route[island_count];
    int index = 0;
    int current = end;

    while (current != -1 && index < island_count) {
        route[index++] = current;
        int next = prev[current];
        if (next == current) {
            mx_printerr("Error: cycle detected in route\n");
            return;
        }
        current = next;
    }

    for (int i = index - 1; i >= 0; i--) {
        const char *island_name = get_island_name_by_index(islands, route[i]);
        if (island_name == NULL) {
            mx_printerr("Error: island name not found\n");
            return;
        }
        mx_printstr(island_name);
        if (i > 0) {
            mx_printstr(" -> ");
        }
    }
    mx_printstr("\n");
}

