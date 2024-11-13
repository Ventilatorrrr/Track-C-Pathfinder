#include "pathfinder.h"

void print_with_separators(t_island *islands, int start, int end, t_route *routes, t_matrix *matrix, int island_count) {

    t_sort_context context;
    context.islands = islands;
    context.cmp = compare_routes;


    merge_sort_routes(&routes, &context);
    int previous_distance = -1; 
    bool first_route = true;

    for (t_route *current = routes; current != NULL; current = current->next) {
       
        if (current->distance != previous_distance || first_route) {
            if (!first_route) {
                mx_printstr("========================================\n");
            }
            
            previous_distance = current->distance;
            first_route = false;
        }

 
        print_shortest_path(islands, start, end, current->path, current->length, matrix, island_count);
    }
}

