#include "pathfinder.h"

void print_distance(int *path, int length, t_matrix *matrix, int island_count) {
    if (length == 2) {  
        mx_printint(matrix->matrix[path[0] * island_count + path[1]]);
    } else {  
        int total_distance = 0;
        for (int i = 0; i < length - 1; i++) {
            int distance = matrix->matrix[path[i] * island_count + path[i + 1]];
            total_distance += distance;

            mx_printint(distance);
            if (i < length - 2) {
                mx_printstr(" + ");
            }
        }
        mx_printstr(" = ");
        mx_printint(total_distance);
    }
}

