#include "pathfinder.h"

void print_shortest_path(t_island *islands, int start, int end, int *path, int length, t_matrix *matrix, int island_count) {
    mx_printstr("========================================\n");


    mx_printstr("Path: ");
    mx_printstr(get_island_name_by_index(islands, end));
    mx_printstr(" -> ");
    mx_printstr(get_island_name_by_index(islands, start));
    mx_printstr("\n");


    mx_printstr("Route: ");
    for (int i = 0; i < length; i++) {
        const char *island_name = get_island_name_by_index(islands, path[i]);
        if (island_name) {
            mx_printstr(island_name);
            if (i < length - 1) {
                mx_printstr(" -> ");
            }
        }
    }
    mx_printstr("\n");


    mx_printstr("Distance: ");
    print_distance(path, length, matrix, island_count);
    mx_printstr("\n========================================\n");
}

