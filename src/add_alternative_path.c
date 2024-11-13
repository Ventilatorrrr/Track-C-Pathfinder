#include "pathfinder.h"

void add_alternative_path(int *prev, int end, int start, t_route **routes, int island_count, int *dist) {
    int temp_path[island_count];
    int length = 0;
    int current = end;

    while (current != -1) {
        if (length >= island_count) return; 
        temp_path[length++] = current;
        if (current == start) break;
        current = prev[current];
    }

 
    for (int i = 0; i < length / 2; i++) {
        int temp = temp_path[i];
        temp_path[i] = temp_path[length - 1 - i];
        temp_path[length - 1 - i] = temp;
    }

   
    if (!is_duplicate_route(*routes, temp_path, length)) {
        add_route(temp_path, length, dist[end], routes);
    }
}

