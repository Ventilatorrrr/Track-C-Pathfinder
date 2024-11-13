#include "pathfinder.h"

void find_shortest_path(t_island *islands, t_matrix *matrix, int start, int end, t_route **routes) {
    int island_count = get_island_count(islands);
    int dist[island_count];
    t_list **prev = malloc(sizeof(t_list *) * island_count);
    bool visited[island_count];

    for (int i = 0; i < island_count; i++) {
        dist[i] = INF;
        visited[i] = false;
        prev[i] = NULL;
    }
    dist[start] = 0;

  
    for (int i = 0; i < island_count; i++) {
        int min_dist = INF, min_index = -1;
        for (int j = 0; j < island_count; j++) {
            if (!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                min_index = j;
            }
        }
        if (min_index == -1) break;
        visited[min_index] = true;

        for (int j = 0; j < island_count; j++) {
            int edge_dist = matrix->matrix[min_index * island_count + j];
            if (edge_dist != INF && !visited[j]) {
                if (dist[min_index] + edge_dist < dist[j]) {
                    dist[j] = dist[min_index] + edge_dist;
                    clear_list(&prev[j]); 
                    add_to_list(&prev[j], min_index);
                }
                else if (dist[min_index] + edge_dist == dist[j]) {
                    add_to_list(&prev[j], min_index);
                }
            }
        }
    }

    if (dist[end] == INF) {
      
        for (int i = 0; i < island_count; i++) {
            clear_list(&prev[i]);
        }
        free(prev);
        return;
    }

    int current = end;  
build_paths(prev, start, current, dist, routes);


   
    for (int i = 0; i < island_count; i++) {
        clear_list(&prev[i]);
    }
    free(prev);
}

