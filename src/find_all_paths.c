#include "pathfinder.h"

void find_all_paths(t_island *islands, t_matrix *matrix) {
    t_visited_path *visited_paths = NULL;
    int island_count = get_island_count(islands);

    for (int start = island_count - 1; start >= 0; start--) {
        for (int end = start - 1; end >= 0; end--) {
            const char *start_name = get_island_name_by_index(islands, start);
            const char *end_name = get_island_name_by_index(islands, end);

            if (!is_path_visited(visited_paths, start_name, end_name)) {
                t_route *routes = NULL;
                find_shortest_path(islands, matrix, start, end, &routes);

                add_to_visited(&visited_paths, start_name, end_name);

                
                print_with_separators(islands, end, start, routes, matrix, island_count);
                t_route *current = routes;
                while (current != NULL) {
                    t_route *temp = current;
                    current = current->next;
                    free(temp->path);
                    free(temp);
                }
            }
        }
    }
    clear_visited(&visited_paths);
}

