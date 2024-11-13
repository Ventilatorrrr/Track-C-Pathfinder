#include "pathfinder.h"

void fill_matrix_with_distances(t_matrix *matrix, t_island *islands) {
    int island_count = get_island_count(islands);
    for (int i = 0; i < island_count * island_count; i++) {
        matrix->matrix[i] = INF;
    }
    for (int i = 0; i < island_count; i++) {
        matrix->matrix[i * island_count + i] = 0;
    }

    t_island *island = islands;
    while (island != NULL) {
        t_path *path = island->path;
        int from_index = get_island_index(islands, island->name);

        while (path != NULL) {
            int to_index = get_island_index(islands, path->nextConnect->name);
            if (from_index >= 0 && to_index >= 0) {
                matrix->matrix[from_index * island_count + to_index] = path->pathDistance;
                matrix->matrix[to_index * island_count + from_index] = path->pathDistance;
            }
            path = path->nextPath;
        }
        island = island->next;
    }
}

